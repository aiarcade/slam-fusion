normalized = function(x){
  return ((x-min(x))/(max(x)-min(x)))
}
gt_data=read.csv("/home//mahesh/out//gs.txt",sep=" ",header=FALSE)
predicted_data=read.csv("/home//mahesh/out/predicted.csv",sep=" ")
attach(mtcars)
par(mfrow=c(2,1))
plot(predicted_data$x,predicted_data$y,main="Predicted")
plot(gt_data$V5+5311.328,gt_data$V6+1023.6008,main="GT")
