
void	err	(short err_code){
	int err_msg = 0;
	switch	(err_code){
		
		case 10:err_msg = "";
			break;
		
		case 11:err_msg = "";
			break;
		
		case 12:err_msg = "";
			break;
		
		case 13:err_msg = "";
			break;
		
		case 14:err_msg = "";
			break;
		
		case 15:err_msg = "";
			break;
		
		case 16:err_msg = "";
			break;
		
		case 17:err_msg = "";
			break;
		
		case 18:err_msg = "";
			break;
		
		case 19:err_msg = "";
			break;
		default:;
	}
	if (err_msg != 0)
		printf	("\n!!!\tError:%s.\n",err_msg);
}

 