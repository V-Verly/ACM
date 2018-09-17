#include<cstdio>
#include<queue>
using namespace std;
struct Message{
    int priority,num,key;
    char text[100];
        bool operator < (const Message&t)const{  
        if(priority==t.priority) return key>t.key;
        else return priority>t.priority;
    }  
};

int main()
{
   Message message;
   char text[20];
   int i=0;
   priority_queue<Message> windows;
   while(scanf("%s",text)!=EOF){
       if(text[0]=='P'){
           scanf("%s%d%d",message.text,&message.num,&message.priority);
       message.key=i;
       windows.push(message);
       i++;
       }
       else{
           if(windows.empty()) printf("EMPTY QUEUE!\n");
           else{
               printf("%s %d\n",windows.top().text,windows.top().num);
               windows.pop();
           }
       }
   }
   return 0;
}