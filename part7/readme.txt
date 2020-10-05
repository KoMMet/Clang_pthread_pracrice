
実行結果
```
max is 2147396060
```

確認点
スレッドローカル変数を作るための仕組みがC言語で提供されている。
pthread_key_t
pthread_getspecific()
pthread_setspecific()
pthread_key_create()
が、使い勝手が悪いので、スレッドの中でスタックにもつのがよいと思われる。
