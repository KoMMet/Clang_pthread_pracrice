
exec
実行結果
```
procFunc writes to standerd output
main writes to standerd optput
```
```
$ cat fdProc.txt
procFunc writes to fdProc.txt
```

確認点
ファイルディスクリプターが子プロセスにコピーされるが、
共有はしていないので、子プロセスでopen先を変えると、
子プロセスのみでopen先が変わり、親プロセスはもとのままになる。

--------------------------------------------------------------------------
exec2

実行結果
```
threadFunc writes to standerd output
```

```
$ cat fdProc.txt
threadFunc writes to fdProc.txt
main writes to standerd optput

```
確認点
スレッドを作ったあとにオープンしたファイルディスクリプターまで共有される
