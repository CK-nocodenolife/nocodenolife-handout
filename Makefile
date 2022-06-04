CMDS = view compile clean cleanall
OUTPUT_DIR = ./output/
CONTENT_DIR = ./content/
TEX = xelatex
TEX_FLAG := -interaction=batchmode -halt-on-error -file-line-error -no-shell-escape -output-directory="$(OUTPUT_DIR)"
FILE = main

.PHONY: $(CMDS)

view:
	@open $(OUTPUT_DIR)$(notdir $(FILE)).pdf

compile:
ifneq ($(FILE), main)
	$(TEX) $(TEX_FLAG) -jobname="$(FILE)" $(CONTENT_DIR)$(FILE).tex
else
	$(TEX) $(TEX_FLAG) $(FILE).tex
endif
	texloganalyser -ew $(OUTPUT_DIR)$(FILE).log
	@open $(OUTPUT_DIR)$(FILE).pdf

clean:
	find $(OUTPUT_DIR) -name "*.aux" -type f -delete
	find $(OUTPUT_DIR) -name "*.log" -type f -delete
	find $(OUTPUT_DIR) -name "*.out" -type f -delete

cleanall: clean
	find $(OUTPUT_DIR) -name "*.pdf" -type f -delete
	find . -name "*.aux" -type f -delete
