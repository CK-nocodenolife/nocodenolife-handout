from panflute import *

def action(elem, doc):
    if isinstance(elem, SoftBreak):
        return LineBreak
    if type(elem) == Header:
        if elem.level < 6:
            elem.level += 2

def main(doc=None):
    return run_filter(action, doc=doc) 

if __name__ == '__main__':
    main()
