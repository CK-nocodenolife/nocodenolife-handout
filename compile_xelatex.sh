#!/bin/bash

xelatex -interaction=batchmode -halt-on-error -file-line-error main.tex && \
    xdg-open main.pdf
