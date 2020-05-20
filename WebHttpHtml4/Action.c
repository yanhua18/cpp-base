Action()
{

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(17);

	lr_start_transaction("1_transaction");

	lr_rendezvous("1");



/*Correlation comment - Do not change!  Original value='{username}' Name ='CorrelationParameter' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CorrelationParameter",
		"LB=blockquote>Welcome, <b>",
		"RB=<",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/login.pl*",
		LAST);

	web_reg_find("Search=Body",
		"Text=Welcome, <b>{username}</b>, to the Web Tours reservation pages.","SaveCount=reservation_Count",
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={username}", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=39", ENDITEM, 
		"Name=login.y", "Value=6", ENDITEM, 
		LAST);

    lr_output_message("USERNAME= %s ",lr_eval_string("{username}"));
    if(strcmp(lr_eval_string("{username}"),"test1")==0)
    {
    	lr_log_message("this is test1");
    }
    else
    {
    	lr_log_message("this is not test1");
    }
	lr_end_transaction("1_transaction",LR_AUTO);

	lr_think_time(8);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t3.inf", 
		LAST);

	return 0;
}