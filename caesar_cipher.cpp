  #include<bits/stdc++.h>
  #include<fstream>
  using namespace std;
  int main()
  {
      int k,p;
      string text,enc,enc_data,dec_data;
      cout<<"Enter the text\n";
      getline(cin,text);
      ofstream o1;
      o1.open("text.text");
      o1<<text;
      cout<<"Enter the key\n";
      cin>>k;
      ofstream o2;
      o2.open("key.text");
      o2<<k;
      ofstream o3;
      o3.open("encrypt.text");
      ofstream o4;
      o4.open("decrypt.text");     
      while(1){
        cout<<"Press 1.Encryption\nPress 2.Decryption\nPress 3.Exit\n";
        cin>>p;
        
        
        
        if(p==1){
            for (int i = 0; i < text.length(); i++){
              if(text[i]==' ')
                enc.push_back(text[i]);
              else{
                char ch = char(text[i]-'a'+k)%26+'a'; 
                enc.push_back(ch);
              }
            }
            cout<<enc<<endl;
            o3<<enc;
        }
        
        
        
        
        if(p==2){
          if(enc.length()==0)
            cout<<"First encyprt your text\n";
          else
          {
            ifstream in;
            in.open("encrypt.text");
            while(!in.eof()){
              char ch = in.get();
              enc_data.push_back(ch);
            }
            // cout<<enc_data;
            for(int i=0;i<enc_data.length();i++){
              if(enc_data[i]==' ')
                dec_data.push_back(' ');
              else{
                char d = char(enc_data[i]-'a'-k)%26 + 'a'; 
                dec_data.push_back(d);
              }
            }
            cout<<dec_data<<endl;
            o4<<dec_data;
          }
        }
        
        
        
        
        if(p==3)
        {
          remove("text.text");
          remove("key.text");
          remove("encrypt.text");
          remove("decrypt.text");
          cout<<"ThankYou\n";
          break;
        }
        o2.close();
        o1.close();
        o3.close();
        o4.close();
      }   
}


