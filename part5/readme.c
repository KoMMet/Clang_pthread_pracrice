実行結果
```
main-1: varA=1 varB=2
proc 1 - 1 : varA:1 varB:4
proc 1 - 2 : varA:5 varB:4
main-2: varA=1 varB=3
proc 2 - 1 : varA:1 varB:8
proc 2 - 2 : varA:10 varB:8
proc 1 - 3 : varA:5 varB:4
proc 1 - 4 : varA:5 varB:6
main-2: varA=5 varB=3
proc 2 - 3 : varA:10 varB:8
proc 2 - 4 : varA:10 varB:12
main-3: varA=10 varB=3
proc 2 - 1 : varA:5 varB:8
proc 2 - 2 : varA:10 varB:8
proc 2 - 3 : varA:10 varB:8
proc 2 - 4 : varA:10 varB:12
main-3: varA=10 varB=3
main-3: varA=5 varB=3
main-3: varA=1 varB=3
```

確認点
forkでマルチプロセスにした場合、プロセスがコピーされるが、
メモリ内容もすべてコピーされるので、変数の値を引き継いでいる。

