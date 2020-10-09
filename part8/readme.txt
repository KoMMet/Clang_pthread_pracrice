
実行結果
```
Number of prime numbers under 100 is 1 ?
Number of prime numbers under 100 is 1 ?
Number of prime numbers under 100 is 1 ?
....
```

確認点
pthreadの排他制御
pthread_mutext_tを使う。

pthread_mutext_init()
pthread_mutext_lock()
pthread_mutext_trylock()
pthread_mutext_unlock()
pthread_mutext_destroy()
