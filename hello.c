#include<stdio.h>
#include<stdlib.h>
#define NOF_PACKETS 10
int rands(int a)
{
int rn=(rand()%10)%a;
return rn==0?1:rn;
}
int main(){
int packet_sz[NOF_PACKETS],i,clk,b_size,o_rate,p_sz_rm=0,p_sz_,p_time,op;
for(i=0;i<NOF_PACKETS;++i)
packet_sz[i]=rands(6)*10;
for(i=0;i<NOF_PACKETS;++i)
printf("\n packet[%d]:%d bytes \t",i,packet_sz[i]);
printf("\n enter he output rate:");
scanf("%d",&o_rate);
printf("\n enter he Bucketsize:");
scanf("%d",&b_size);
for(i=0;i<NOF_PACKETS;++i)
{
if((packet_sz[i]+p_sz_rm)>b_size)
if(packet_sz[i]>b_size)
printf("\n\n Incoming packet size(%d bytes) is greater than bucket capacity exceeded PACKETS REJECTED");
else
{
p_sz_rm+=packet_sz[i];
printf("\n\n incoming packet size:%d",packet_sz[i]);
printf("\n Bytes remaining to transmit:%d",p_sz_rm);
p_time=rands(4)*10;
printf("\n Time left for transmission:%d units",p_time);
for(clk=10;clk<=p_time;clk+=10)
{
sleep(1);
if(p_sz_rm)
{
if(p_sz_rm<=o_rate)
op=p_sz_rm,p_sz_rm=0;
else
op=o_rate,p_sz_rm-=o_rate;
printf("\n packet of size %d transmitted",op);
printf("------ Bytes remaining to transmit:%d",p_sz_rm);
}
else
{
printf("\n time left for tramission:%d units",p_time-clk);
printf("\n No packets to transmit !!");
}
}
}
}
return 0;
}

