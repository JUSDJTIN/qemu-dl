# qemu-dl
### this is a homework
* record the pc ...
* about the time control :
  * change the icebp ins ,and use it to control the flag 
* how to use 
  * sudo ./configure
  * sudo make && make install 
  ***
### 更新说明(1.0)：
* 修改记录函数
* 添加所需要的记录信息
* 使用说明：
* 修改 target-i386/translate.c 中path 为你自己的文件夹即可，函数会自动创建文件
* 创建文件说明：

  * 文件命名规则:messagename_num.log
  * messagename:是所需记录的信息
  * num:是第几次进行记录(从0开始)

### 更新说明(1.0.01)：
* 修复部分bug
* 优化记录函数
* 使用说明：在target-i386/my_debug.h　中修改自己的文件路径

  *** 
  ### bugs:
 * 在windows下有时会自己执行　icebp　指令，触发记录信息函数，目前还没发现为什么windows会在正常运行时执行这条命令．
 * 程序记录的信息中，在凌晨的0-8点之间日期会比实际的时期晚一天，但是由于这个时间段大家都在休息，所以就先不修复了．
 * 由于本人能力有限，所以不免存在其他没有发现的bug,如有发现，敬请指出，不胜感激．


