creation_histo =function(N,namefile,dt){
	jpeg(namefile)
	hist(dt[,1],main=paste("temps de coalescence pour N= ",N),xlab="temps de coalescence",col="sienna")
	abline(v=N,col="coral")
	abline(v=mean(dt[,1]),col="brown4")
	legend("topright", legend=c(paste("esperance observée  : ",mean(dt[,1])),paste("esperance théorique : ",N)), col=c("brown4","coral"),pch="❀")
	dev.off()
}

cal_var_theo=function(N){
	p=1/N
	q=1-p
	var=q/p**2
	return(var)
}

creation_tout=function(deb,fin,intervalle){
	nom=paste("tab_res",deb,"_",fin,"_",intervalle,".txt")
	sink(nom)
	print(paste("esperance theorique","esperance empirique","différence ","variance theo", "variance emp", "diff"))
	for(i in seq(deb,fin,intervalle)){
		nom_fichier=paste("res_N",i,".txt",sep="")
		dt=read.table(nom_fichier)
		print(paste(i,mean(dt[,1]),mean(dt[,1])-i,cal_var_theo(i), var(dt[,1]),cal_var_theo(i)-var(dt[,1]) ))
		nom_sortie=paste("histo_N",i,".jpeg",sep="")
		creation_histo(i,nom_sortie,dt)
	}
	sink()
}

creation_tout(200,1000,100)

#jpeg("hist_2k_N600.jpeg")
#hist(dt[,1],main="temps de coalescence pour N=600",xlab="temps de coalescence",col="sienna")
#abline(v=600,col="coral")
#abline(v=mean(dt[,1]),col="brown4")
#legend("topright", legend=c(paste("esperance observée  : ",mean(dt[,1])),paste("esperance théorique : ",600)), col=c("brown4","coral"),pch="❀")
#dev.off()
