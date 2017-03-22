# ExeLauncher

任意のexeをただ実行するためだけのランチャーを作れるプロジェクトです。

## 使い道

Electronのwinビルドでは、とてもファイルが多く煩雑です。そこで、Electronの出力したファイル群をフォルダでまとめ、同じ階層にElectronアプリを起動するこのランチャーを設置することで、ユーザーが迷うことなくプログラムを実行できます。

## カスタマイズ方法

### ソース(Main.c)

#### 実行プログラム

6行目付近にある、以下の `notepad.exe` を任意の物に書き換えます。

```
#define EXE_PATH "notepad.exe"
```

#### リソース

バージョン情報などを書き換える場合は、 `Resource.rc` を編集してください。Visual Studioの場合、ソリューションエクスプローラーでこのファイルの上で右クリック→コードの表示で編集可能です。

### アイコン(icon.ico)

アイコンを上書きしてください。

## ビルド

Visual Studioでビルドしてください。

このプロジェクトはVisual Studio 2017で作られているので、Visual Studio Installerで　`C++によるデスクトップ開発` をインストールしておいてください。

## その他

### アイコンについて

実行対象のexeと同じものを使うようにしましょう。

icoファイルは [@icon](http://www.vector.co.jp/soft/win95/amuse/se201729.html) を使うと、透過PNGの画像をまとめて1つのicoファイルにすることができ、非常に便利です。

アイコンサイズに関してはよく分からなかったのでとりあえずデフォルトのは以下のサイズを突っ込みました。正しい情報が見つかれば何とかしたいところです。

* 16
* 20
* 24
* 32
* 40
* 48
* 64
* 128
* 256

### 内部処理について

これはWinAPIの `CreateProcess` を用いて作られています。引数が多いのでいくつか注意事項があります。

* `STARTUPINFO` のデータはサイズ `cb` がないとだめです。
* 第二引数に実行パスを入れるのですが、これはdefine等で定義した書き換え不可能なメモリ領域のポインタを与えると例外で落ちます。
    * このプログラムのように、面倒ではありますが文字列を確保して代入し、その文字列のポインタを与えましょう。

## 今後について

* 引数引継ぎとかしたい。
* 同じ階層に設定ファイルがあったらその設定を使って起動など、需要があれば。
