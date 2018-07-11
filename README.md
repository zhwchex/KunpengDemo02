# KunpengDemo02
使用vs打开"KunpengDemo02\proj.win32\KunpengDemo02.sln"，点击绿色三角箭头调试。

有可能遇到路径问题

该项目由VS2013编译，VS2013直接跑通。VS2015跑不通，一个解决办法是用VS2015编译一个COCOS2DX HELLOWORLD，在这个HELLOWORLD项目里找本项目缺失的libbullet-2015.lib文件。

WASD移动，JKL技能。

完成了一个getHurt的猿们请考虑被风弹、爪子、漩涡、鱼鳍、摔在地上、被冲撞这六种受击动画。

工作量太大了，我现在慌得一批


出招表：

wsad：方向键，普通移动。

j:普通攻击。

k：冲刺。

方向键+k：带方向的冲刺。

鹏进入水下：变成鲲。

鲲不能游出水面，但可以借助冲刺跃出水面。

鲲在空中时，j：吐水球。

鲲在空中时，k：变成鹏。

