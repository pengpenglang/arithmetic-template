# ACM-ICPC CheatSheet
![python](https://img.shields.io/badge/python-3.5-ff69b4.svg)

ACM-ICPC模板

## Feature
* 维护模板代码，自动生成PDF，[CheatSheet.pdf](CheatSheet.pdf)
* 代码高亮，代码中渲染数学公式
* 可直接插入`tex`文件
* 仅包含一个文件的目录，会将该文件直接作为一个章节
* 已有模板仅作为参考

## Usage
1. 模板代码
    
    * 依照`/src`目录下的格式进行排布。

2. 设置

    * 自行配置`xelatex`编译环境
    * `CheatSheet.sty`: 修改latex的相关样式
    * `CheatSheet.tex`: 修改`Title`或`Owner Information`部分的信息
    * `settings.py`: 请在此文件中添加其他代码语言

3. 运行

    `make build`

## License
[MIT License](LICENSE)

## Demo
![](demo.png)
