# GamePad制御のC＋＋コードサンプル
Cobra Joystick V6を買ったので、制御を理解するためのプログラムを書いてみました。
https://flashfire.tw/en/supports/8b0eea/item

ボタンを押したり、ジョイスティックを操作しすると、mainからスコープできる「std::atomic<DIJOYSTATE2>* GamePadOBJtOutMode」構造体の中にデータが入ってきます。
