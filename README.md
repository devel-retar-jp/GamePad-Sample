# GamePad制御のC＋＋コードサンプル
Cobra Joystick V6を買ったので、制御を理解するためのプログラムを書いてみました。

https://flashfire.tw/en/supports/8b0eea/item

ボタンを押したり、ジョイスティックを操作しすると、mainからスコープできる「std::atomic<DIJOYSTATE2>* GamePadOBJtOutMode」構造体の中にデータが入ってきます。

2つほど、効かないボタンがありますが、通常の制御では十分。

他社のメーカーのゲームパットなどでのボタンと信号の関係がわかります。
