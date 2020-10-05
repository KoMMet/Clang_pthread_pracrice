実行結果
  ```
  main-1: varA=1 varB=2
  thread 1 - 1: varA:1 varB:4
  thread 1 - 2: varA:5 varB:4
  main-2: varA=5 varB=3
  thread 2 - 1: varA:5 varB:8
  thread 2 - 2: varA:10 varB:8
  thread 1 - 3: varA:10 varB:4
  thread 1 - 4: varA:10 varB:6
  thread 2 - 3: varA:10 varB:8
  thread 2 - 4: varA:10 varB:12
  main-3: varA=10 varB=3
  ```

確認点
スレッドの外で作った変数varAは他のスレッドの影響を受けるが、
スレッドの中で作った変数varBは他のスレッドの影響を受けない。
