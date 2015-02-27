# val[0][3]); 4
# val[1][3]); 
# val[2][3];
# 
# 00 01 02 03 10 11 12 13 20 21 22 23 
# 1   2  3  4  5  6  7  8  9 10 11 12   
# 
# 4,8,12

gt_data=read.csv("/home//mahesh/out/gs.txt",sep=" ",header=FALSE)
p_data=read.csv("/home//mahesh/out/predicted.csv",sep=" ",header=FALSE)

new_gt=data.frame(p_data[,1:3],gt_data$V5,p_data[,5:7],gt_data$V6,p_data[,9:11],gt_data$V7)
?write.csv
write.table(new_gt,file="00.txt",sep=" ",col.names=FALSE,
            row.names=FALSE)
