#include <bits/stdc++.h>
using namespace std;
int main()
{

	ofstream outfile("Output_File.txt"); //this creates it. 
	ifstream infile1("followers.html"); //opens the file for reading
	ifstream infile2("following.html"); //opens the file for reading

	string line1,line2;
	string txt1,txt2;
	
	map<string,bool> followingMap;
	map<string,bool> followersMap;
	
	// Get all following
	while (getline(infile2, line2))
	{
	    	istringstream iss2(line2);
		
		string prev="";

		if(line2.find("_9mmn5")+1)
		while(iss2 >> txt2)
		{
			//if(txt2.substr(0,32)=="href=\"https://www.instagram.com/"&&txt2.substr(txt2.length()-3)=="div"){
			if(txt2.find("class=\"_9mmn5\"")!=-1){
				int x=(prev.length()-49)/2;			
				prev=prev.substr(prev.length()-(14+x),x);
				
				string outline="";
				do{
					outline+=txt2;
					if(txt2.length()>=3&&txt2.substr(txt2.length()-3)=="div"){
						outline=prev+"@@@"+outline.substr(15,outline.length()-(22+15));
						
						if(followingMap.find(outline)!=followingMap.end())
							outline+="vedahi";
						followingMap[outline]=true;

						break;
					}
				}while(iss2 >> txt2);
			}

			prev=txt2;
		}	
	}
	
	// Get all followers
	while (getline(infile1, line1))
	{
	    	istringstream iss1(line1);
		
		string prev="";

		if(line1.find("_9mmn5")+1)
		while(iss1 >> txt1)
		{
			if(txt1.find("class=\"_9mmn5\"")!=-1){
				int x=(prev.length()-49)/2;			
				prev=prev.substr(prev.length()-(14+x),x);
				
				string outline="";
				do{
					outline+=txt1;
					if(txt1.length()>=3&&txt1.substr(txt1.length()-3)=="div"){
						outline=prev+"@@@"+outline.substr(15,outline.length()-(22+15));
						
						if(followersMap.find(outline)!=followersMap.end())
							outline+="vedahi";
						followersMap[outline]=true;

						break;
					}
				}while(iss1 >> txt1);
			}

			prev=txt1;
		}	
	}

	int count=0;
	// These are the snitches
	for (std::map<string,bool>::iterator it=followingMap.begin(); it!=followingMap.end(); ++it){
		if(followersMap.find(it->first)==followersMap.end()){
			outfile<<it->first<<"\n\n";
			count++;
		}
	}

	outfile.close();
	infile1.close();
	infile2.close();

	cout<<"\nAll Done !\n\nFound Bad People : "<<count<<"\n\n"<<followingMap.size()<<" "<<followersMap.size()<<"\n\n";
	system("sleep 1");
	return 0;
}
