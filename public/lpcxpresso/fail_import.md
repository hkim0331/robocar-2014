## import に失敗したら?

次の手順で失敗したプロジェクトを消し、新たにプロジェクトをインポートすべし。

1. インポート失敗プロジェクトの上で右クリック、
2. 現れるメニューから Delete を選択、
3. いったん lpcxpresso を終了、
4. ターミナル開いて、インポート失敗プロジェクトの残骸が残っていることを確認。
````
$ ls -l robocar/workspace
total 0
drwxr-xr-x 12 hkim staff 408 10 15 13:48 kirakira
drwxr-xr-x 12 hkim staff 408 10 14 09:49 robocar
````
5. インポート失敗したプロジェクト名が残っていたら(上の例では robocar)、
それを消す。このコマンドは強力で、まちがうと取り返しがつきません。慎重に。
````
$ rm -rf robocar/workspace/robocar
````

この後、LPCXpresso を再度立ち上げ、プロジェクトをインポートし直す。

[back](/)

----
written by hkimura.