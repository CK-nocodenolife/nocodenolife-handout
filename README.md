# nocodenolife-handout

## Prequisites

- 會使用 Git 及 GitHub。
學習資源：[連猴子都能懂的 Git 入門指南](https://backlog.com/git-tutorial/tw/)
- 會使用終端機打 `make` 指令。
下面會教怎麼做。
- 會使用基本的 $\LaTeX$ 做文書處理。（不是只有打數學式喔！）
學習資源：
    - [PAPAYA 電腦教室的影片](https://youtu.be/mQamBS6uTOc)
    - [Overleaf 的教學](https://www.overleaf.com/learn/latex/Tutorials)
- 會好好打標點符號
- 會你要寫的講義內容
    - 其實不會好像也沒差

以上東西如果不會的話就趁這個機會學起來吧。

## Repo 使用方式

- Commit message 請註明修改哪個章節。
- 請記得要先 `git pull` 再修改。
- 編輯自己的部份請自行開新的 branch ，完成後再發 pull request。
	- 不知道怎麼做請去查 GitHub 教學，我也不會。
- 請在對應的分類底下開自己的檔案，例如：進階圖論放在 `content/Graph/Advanced.tex` 。

## LaTeX 使用方式

### 編譯及環境

- Overleaf 上編譯 code 的字體會怪怪的，會介意的話請本機安裝 `texlive` 之類的。套件有點多，如果空間充足的話建議直接安裝 `texlive-full`。
- 如果要編譯整份，請直接在根資料夾裡面打 `make compile` 。
- 如果要編譯單個章節（單個檔案），請使用 `make compile FILE=path/to/file` 。例如：只要編譯進階圖論，請用 `make compile FILE=Graph/Advanced` 。注意，不需要加 `content/` ，也不需要打副檔名。

### 內容格式

詳細使用方式可以參考 `Sample/Sample.tex` 。
想要編譯單個檔案的話，請記的要用以下幾行包住整個內容：

```tex
\documentclass[main.tex]{subfiles}
\begin{document}

% 你的內容

\end{document}
```

#### `C++` 程式碼
```line=1
\begin{C++}
#include <iostream>

int main() {
    std::cout << "Hello, world" << std::endl;
}
\end{C++}
```

```line=1
\inline{lower_bound}
```

#### 其他
```line=1
\theorem{定理名稱}{內容} % 定理＋自動編號＋定理名稱
\lemma{引理名稱}{內容} % 引理＋自動編號＋引理名稱
\definition{定義名稱}{內容} % 定義＋自動編號＋定義名稱
\eeric{內容} % 跟著蕭電這樣做
\hint{內容} % 提示框
\problem{題目名稱（Judge＋題號）}{
    題敘＋數字範圍
} % 習題
```

### 文字格式

- 請先閱讀 [此文件](https://github.com/sparanoid/chinese-copywriting-guidelines) 。
- 編寫時請按照上述格式，數學式前後請比照數字做空格。

### 程式碼要求

- 變數名稱請盡量有意義，題解盡可能使用與題目敘述相同的符號。
例如前綴和使用 `pre[]` 較 `a[]` 佳。
- 盡量不要使用自己的 default code 。`#define ll long long` 等常見者例外。
- 如果可以的話請丟給 `clang-format` 排一遍。
