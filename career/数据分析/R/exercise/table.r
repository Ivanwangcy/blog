a = read.csv("~/workspace/blog/career/数据分析/R/exercise/表格.csv")
attach(a)

# table
table(a[,1])
table(a[,2])
table(a)

# ftable
ftable(a[,1],row.vars=1)
ftable(a[,2],row.vars=1)
ftable(a,row.vars=1)

# xtabs
xtabs(~文化程度, a)
xtabs(~性别, a)
xtabs(~., a)