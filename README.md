# grpc_test
Copyright Takuma Tachibana

## 概要
このリポジトリはテクノプレナーインターンシップで作成したGRPC性能評価プログラムです

## フォルダ説明
* myexamples/
 * cpyhello ：pythonクライアント、c++サーバでのHelloWorld
 * cvBinSendSample :  バイナリ、非圧縮で通信した性能検証プログラム
 * cvencodeSendSample : バイナリ、jpg圧縮で通信した性能検証プログラム
 * cvSendSample : 数値で通信した性能検証プログラム
 * imProcessingBench : OpenCVベンチマークプログラム
* protos/
 * cpyhello.proto : myexamples/cpyhello用protoファイル
 * cvgrpc.proto : myexamples/cvSendSample用protoファイル
 * cvgrpc_bin.proto : myexamples/cvBinSendSample , myexamples/cvencodeSendSample用protoファイル
* 0915report.md ： OpenCVのベンチマーク結果について
* 0926report.md : 性能検証プログラムの実行方法について
* enviroment_install.md : 環境構築について
