library(showtext)
f= c(10,19,46,18,3)
font_files()
showtext_auto(enable = TRUE)
# font_add('Songti')

# quartz(family = 'ArialUnicodeMS')

# 自定义 柱状体
# barplot(f, col=2:6, names.arg = c("高中", "专科", "本科", "硕士研究生", "博士研究生"))
# 设置坐标轴的名称和颜色
# title(xlab = "学历", ylab = "人数")


# ![](https://raw.githubusercontent.com/lih627/MyImages/master/images/%E5%AD%A6%E5%8E%86.png)

a = read.csv("~/workspace/blog/career/数据分析/R/exercise/表格.csv")
attach(a)

barplot(table(a[,1]), col = 2:6)
