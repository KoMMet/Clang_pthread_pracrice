main.c
  実行結果
    ```
    main 0
    func 0
    main 1
    func 1
    exit
    main 2
    ```
  確認点
  pthread_exitでスレッドが終了すること。

2main.c
  実行結果
  ```
  ./exec2  6
  main 0
  threadfunc 0
  threadfunc 1
  main 1
  threadfunc 2
  main 2
  threadfunc 3
  main 3
  threadfunc 4
  main 4
  threadfunc 5
  ```
  確認点
  引数でループが変わる
