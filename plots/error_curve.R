normalized = function(x){
  return(x)#((x-min(x))/(max(x)-min(x)))
}

gt_data=read.csv("/home//mahesh/out//gs.txt",sep=" ",header=FALSE)
predicted_data=read.csv("/home//mahesh/out/predicted.csv",sep=" ",header=FALSE)

rotateX=function(p,rad){
  cosa =cos(rad)
  sina = sin(rad)
  y = p[2] * cosa - p[3] * sina
  z = p[2] * sina + p[3] * cosa
  return(c(p[1],y,z))
}

rotateY=function(p,rad){
  cosa =cos(rad)
  sina = sin(rad)
  z = p[3] * cosa - p[1] * sina
  x = p[3] * sina + p[1] * cosa
  return(c(x,p[2],z))
}

rotateZ=function(p,rad){
  cosa =cos(rad)
  sina = sin(rad)
  x = p[1] * cosa - p[2] * sina
  y = p[1] * sina + p[2] * cosa
  return(c(x,y,p[3]))
}


gt_data$V5=gt_data$V5+5311.328
gt_data$V6=gt_data$V6+1023.6008
gt_data$V7=gt_data$V7-114.1870
org_gt=read.csv("/home//mahesh/out//gs.txt",sep=" ",header=FALSE)
for(i in 1:length(gt_data$V5)){
  
  gt_data[i,5:7]=rotateY(c(gt_data$V5[i],gt_data$V6[i],gt_data$V7[i]),3.14)
}
attach(mtcars)
par(mfrow=c(3,1))
plot(gt_data$V5,gt_data$V7,main="RGT")
plot(org_gt$V5,org_gt$V7,main="GT")
plot(predicted_data$x,predicted_data$z,main="PR")
# attach(mtcars)
# par(mfrow=c(2,1))
# plot(predicted_data$x,predicted_data$y,main="Predicted")
# plot(gt_data$V5+5311.328,gt_data$V6+1023.6008,main="GT")
#gt_data$V5=gt_data$V5+5311.328
#gt_data$V6=gt_data$V6+1023.6008
# n_gtx=normalized(gt_data$V5)
# n_gty=normalized(gt_data$V6)
# n_gtz=normalized(gt_data$V7)
# px=normalized(predicted_data$x)
# py=normalized(predicted_data$y)
# pz=normalized(predicted_data$z)
# attach(mtcars)
# par(mfrow=c(4,3))
# 
# plot(n_gtx,n_gty)
# plot(n_gtx,n_gtz)
# plot(n_gty,n_gtz)
# plot(px,py)
# plot(px,pz)
# plot(py,pz)
# 
# plot(n_gty,n_gtx)
# plot(n_gtz,n_gtx)
# plot(n_gtz,n_gty)
# plot(py,px)
# plot(pz,px)
# plot(pz,py)


