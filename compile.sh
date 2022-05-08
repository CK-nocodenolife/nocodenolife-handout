#!/bin/bash

xelatex -interaction=batchmode -halt-on-error -file-line-error -no-shell-escape main.tex
xdg-open main.pdf
