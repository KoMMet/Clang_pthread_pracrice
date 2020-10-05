実行結果
```
main-1: varA=good morning
thread 1 : varA:hello.1
main-2: varA=hello.1
thread 2 : varA:hello.2
thread 1 : after 2 secs. varA is :hello.2
thread 2 : after 2 secs. varA is :hello.2
main-3: varA=hello.2
```

確認点
varAはmallocによってヒープに作られているため、全スレッドで共有され、
書き換えあうこと。
