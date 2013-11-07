# Weblio Popup
## 概要
なにか文書を読みながらわからない英単語を調べるときに、賢い無料の辞書を使いたいという要望に応えてみました。  
`Ctrl+F12`を押すとポップアップし、すぐにテキストボックスにフォーカスが合わさり、インクリメンタルサーチで英単語・日本語の相互の翻訳を出し、適切な位置までスクロールします。また、もう一度`Ctrl+F12`を押すと消えてくれます。

## 使い方
次に述べるインスト―ル方法に従った場合は、以下のコマンドで実行出来ます。
```
$ weblio-popup &
```

起動したらとりあえず`Ctrl+F12`を押し、ポップアップした状態でhello、などと打ってみてください。気が済んだら、もう一度`Ctrl+F12`を押しましょう。

## インストール
- 必要
-- Qt4 (4.8.4でテスト済)
-- Qxt (0.6.1-7でテスト済)

Ubuntu 13.10では以下でインストール可能
```
$ sudo apt-get install qt4-qmake libqt4-dev libqxt-dev
```

- 以下のようなコマンドでビルドできます。
```
$ git clone https://github.com/amiq11/weblio-popup.git
$ cd weblio-popup
$ qmake-qt4
$ make
$ sudo cp popupDictionary /usr/local/bin/weblio-popup
```

# LICENSE
This software is released under the MIT License, see LICENSE.txt.
