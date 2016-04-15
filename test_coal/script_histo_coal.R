	dt=read.table("N.txt",sep="\t");

	for(i in 1:ncol(dt)){
		namefile=paste("N",i,"0.jpeg",sep="")
		jpeg(namefile)
		hist(dt[,i],main="distribution des temps de coalescence",xlab="temps de coalescence", col="aquamarine4")
		dev.off()
	}
