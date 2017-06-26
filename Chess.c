#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum player{P1=1,P2};
enum a{UP=1,TOP_RIGHT,RIGHT,BOTTOM_RIGHT,DOWN,BOTTOM_LEFT,LEFT,TOP_LEFT,TOP_RIGHT2,TOP_RIGHT1,BOTTOM_RIGHT1,BOTTOM_RIGHT2,BOTTOM_LEFT2,BOTTOM_LEFT1,TOP_LEFT1,TOP_LEFT2};
int rook_verify(int To[3],int From[3])
{
    if(((abs(To[0]-From[0])==0)||(abs(To[1]-From[1])==0)) && ((abs(To[0]-From[0])!=0)||(abs(To[1]-From[1])!=0)))
    return 1;
    else
        return 0;
}
int knight_verify(int To[3],int From[3])
{
    if(((abs(To[0]-From[0])==1) &&  (abs(To[1]-From[1]==2))) || ((abs(To[0]-From[0])==2) && (abs(To[1]-From[1])==1)))
        return 1;
    else
        return 0;
}
int bishop_verify(int To[3],int From[3])
{
    if((abs(From[0]+From[1])==abs(To[0]+To[1])) || (abs(From[0]+To[1])==From[1]+To[0]))
        return 1;
    else
        return 0;
}
int queen_verify(int To[3],int From[3])
{
    if((((abs(To[0]-From[0])==0)||(abs(To[1]-From[1])==0)) && ((abs(To[0]-From[0])!=0)||(abs(To[1]-From[1])!=0))) ||((abs(From[0]+From[1])==abs(To[0]+To[1])) || (abs(From[0]+To[1])==From[1]+To[0])))
        return 1;
    else
        return 0;
}
int king_verify(int To[3],int From[3])
{
    if((abs(To[0]-From[0])==1) || (abs(To[1]-From[1])==1) ||  ((abs(To[0]-From[0])==1) && (abs(To[1]-From[1])==1)))
        return 1;
    else
        return 0;
}
int pawn_verify(int To[3],int From[3],char pos[][9])
{
    if(pos[From[0]-1][From[1]-1]=='P')
        {
        if((((To[0]-From[0])==1) || (To[0]-From[0]==2)) && (To[1]-From[1]==0) && (From[0]==2))
            return 1;
        else if(((To[0]-From[0])==1) && (To[1]-From[1]==0))
            return 1;
        else if(pos[To[0]-1][To[1]-1]!=' ')
        {
         if(((To[0]-From[0])==1) && ((abs(To[1]-From[1]))==1))
            return 1;
        else
            return 0;
        }
        }
    else if(pos[From[0]-1][From[1]-1]=='p')
        {
        if((((From[0]-To[0])==1) || (From[0]-To[0]==2)) && (From[1]-To[1]==0) &&(From[0]==7))
            return 1;
        else if(((From[0]-To[0])==1) && (From[1]-To[1]==0))
            return 1;
        else if(pos[To[0]-1][To[1]-1]!=' ')
            {
            if(((From[0]-To[0])==1) && ((abs(From[1]-To[1]))==1))
                return 1;
            else
                return 0;
            }
        }
return 0;
}
int rook_obstacle(int To[3],int from0,int from1,char pos[][9],int dir)
{
if(dir==UP)
{
    if((from0+1)==To[0] && from1==To[1])
        return 1;
    if(pos[from0][from1-1]==' ')
    {
        return rook_obstacle(To,from0+1,from1,pos,dir);
    }
    else
        return 0;
}
else if(dir==DOWN)
{
    if((from0-1)==To[0] && from1==To[1])
        return 1;
    if(pos[from0-2][from1-1]==' ')
    {
        return rook_obstacle(To,from0-1,from1,pos,dir);
    }
    else
        return 0;
}
else if(dir==RIGHT)
{
    if(from0==To[0] && (from1+1)==To[1])
        return 1;
    if(pos[from0-1][from1]==' ')
    {
        return rook_obstacle(To,from0,from1+1,pos,dir);
    }
    else
        return 0;
}
else if(dir==LEFT)
{
    if(from0==To[0] && (from1-1)==To[1])
         return 1;
    if(pos[from0-1][from1-2]==' ')
    {
        return rook_obstacle(To,from0,from1-1,pos,dir);
    }
    else
        return 0;
}
return 0;
}
int bishop_obstacle(int To[2],int from0,int from1,char pos[][9],int dir)
{

if(dir==TOP_RIGHT)
{
    if((from0+1)==To[0] && (from1+1)==To[1])
        return 1;
    if(pos[from0][from1]==' ')
    {
        return bishop_obstacle(To,from0+1,from1+1,pos,dir);
    }
    else
        return 0;
}
else if(dir==TOP_LEFT)
{
    if((from0+1)==To[0] && (from1-1)==To[1])
        return 1;
    if(pos[from0][from1-2]==' ')
    {
        return bishop_obstacle(To,from0+1,from1-1,pos,dir);
    }
    else
        return 0;
}
else if(dir==BOTTOM_RIGHT)
{
    if((from0-1)==To[0] && (from1+1)==To[1])
        return 1;
    if(pos[from0-2][from1]==' ')
    {
        return bishop_obstacle(To,from0-1,from1+1,pos,dir);
    }
    else
        return 0;
}
else if(dir==BOTTOM_LEFT)
{
    if((from0-1)==To[0] && (from1-1)==To[1])
        return 1;
    if(pos[from0-2][from1-2]==' ')
    {
        return bishop_obstacle(To,from0-1,from1-1,pos,dir);
    }
    else
        return 0;
}
return 0;
}
int queen_obstacle(int To[2],int from0,int from1,char pos[][9],int dir)
{
if(dir==UP)
{
    if((from0+1)==To[0] && from1==To[1])
        return 1;
    if(pos[from0][from1-1]==' ')
    {
        return queen_obstacle(To,from0+1,from1,pos,dir);
    }
    else
        return 0;
}
else if(dir==DOWN)
{
    if((from0-1)==To[0] && from1==To[1])
        return 1;
    if(pos[from0-2][from1-1]==' ')
    {
        return queen_obstacle(To,from0-1,from1,pos,dir);
    }
    else
        return 0;
}
else if(dir==RIGHT)
{
    if(from0==To[0] && (from1+1)==To[1])
        return 1;
    if(pos[from0-1][from1]==' ')
    {
        return queen_obstacle(To,from0,from1+1,pos,dir);
    }
    else
        return 0;
}
else if(dir==LEFT)
{
    if(from0==To[0] && (from1-1)==To[1])
        return 1;
    if(pos[from0-1][from1-2]==' ')
    {
        return queen_obstacle(To,from0,from1-1,pos,dir);
    }
    else
        return 0;
}
else if(dir==TOP_RIGHT)
{
    if((from0+1)==To[0] && (from1+1)==To[1])
        return 1;
    if(pos[from0][from1]==' ')
    {
        return queen_obstacle(To,from0+1,from1+1,pos,dir);
    }
    else
        return 0;
}
else if(dir==TOP_LEFT)
{
    if((from0+1)==To[0] && (from1-1)==To[1])
        return 1;
    if(pos[from0][from1-2]==' ')
    {
        return queen_obstacle(To,from0+1,from1-1,pos,dir);
    }
    else
        return 0;
}
else if(dir==BOTTOM_RIGHT)
{
    if((from0-1)==To[0] && (from1+1)==To[1])
        return 1;
    if(pos[from0-2][from1]==' ')
    {
        return queen_obstacle(To,from0-1,from1+1,pos,dir);
    }
    else
        return 0;
}
else if(dir==BOTTOM_LEFT)
{
    if((from0-1)==To[0] && (from1-1)==To[1])
        return 1;
    if(pos[from0-2][from1-2]==' ')
    {
        return queen_obstacle(To,from0-1,from1-1,pos,dir);
    }
    else
        return 0;
}
return 0;
}
int king_check(int i,int j,int I,int J,char pos[][9],int side,int dir)
{
    if(dir==UP)// UP
    {
        if(side==P1)
        {

            if(pos[i+1][j]==' ' || pos[i+1][j]=='r' || pos[i+1][j]=='q')
            {

                if(pos[i+1][j]=='q' || pos[i+1][j]=='r')
                    {
                        return 1;
                    }
                else
                    return king_check(i+1,j,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i+1][j]==' ' || pos[i+1][j]=='R' || pos[i+1][j]=='Q')
            {

                if(pos[i+1][j]=='Q' || pos[i+1][j]=='R')
                    {
                        return 1;
                    }
                else
                    return king_check(i+1,j,I,J,pos,side,dir);
            }
            else
               return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==DOWN)//DOWN
    {
        if(side==P1)
        {

            if(pos[i-1][j]==' ' || pos[i-1][j]=='r' || pos[i-1][j]=='q')
            {

                if(pos[i-1][j]=='q' || pos[i-1][j]=='r')
                   {
                        return 1;
                    }
                else
                    return king_check(i-1,j,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i-1][j]==' ' || pos[i-1][j]=='R' || pos[i-1][j]=='Q')
            {
                //printf("sdf\n");
                if(pos[i-1][j]=='Q' || pos[i-1][j]=='R')
                    {
                        return 1;
                    }
                else
                    return king_check(i-1,j,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==RIGHT)//RIGHT
    {
        if(side==P1)
        {
            if(pos[i][j+1]==' ' || pos[i][j+1]=='r' || pos[i][j+1]=='q')
            {

                if(pos[i][j+1]=='q' || pos[i-1][j]=='r')
                    {
                        return 1;
                    }
                else
                    return king_check(i,j+1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i][j+1]==' ' || pos[i][j+1]=='R' || pos[i][j+1]=='Q')
            {

                if(pos[i][j+1]=='Q' || pos[i][j+1]=='R')
                    {
                        return 1;
                    }
                else
                    return king_check(i,j+1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==LEFT)//LEFT
    {
        if(side==P1)
        {
            if(pos[i][j-1]==' ' || pos[i][j-1]=='r' || pos[i][j-1]=='q')
            {

                if(pos[i][j-1]=='q' || pos[i][j-1]=='r')
                    {
                        return 1;
                    }
                else
                    return king_check(i,j-1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i][j-1]==' ' || pos[i][j-1]=='R' || pos[i][j-1]=='Q')
            {

                if(pos[i][j-1]=='Q' || pos[i][j-1]=='R')
                    {
                    return 1;
                    }
                else
                    return king_check(i,j-1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==TOP_RIGHT)//TOP RIGHT
    {
        if(side==P1)
        {
            if(pos[i+1][j+1]==' ' || pos[i+1][j+1]=='b' || pos[i+1][j+1]=='q')
            {

                if(pos[i+1][j+1]=='q' || pos[i+1][j+1]=='b')
                    {
                        return 1;
                    }
                else
                    return king_check(i+1,j+1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i+1][j+1]==' ' || pos[i+1][j+1]=='B' || pos[i+1][j+1]=='Q')
            {

                if(pos[i+1][j+1]=='Q'|| pos[i+1][j+1]=='B')
                    {
                        return 1;
                    }
                return king_check(i+1,j+1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==BOTTOM_RIGHT)
    {
        if(side==P1)
        {
            if(pos[i-1][j+1]==' ' || pos[i-1][j+1]=='b' || pos[i-1][j+1]=='q')
            {

                if(pos[i-1][j+1]=='q' || pos[i-1][j+1]=='b')
                    {
                        return 1;
                    }
                else
                    return king_check(i-1,j+1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i-1][j+1]==' ' || pos[i-1][j+1]=='B' || pos[i-1][j+1]=='Q')
            {

                if(pos[i-1][j+1]=='Q' || pos[i-1][j+1]=='B')
                    {
                        return 1;
                    }
                else
                    return king_check(i-1,j+1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==BOTTOM_LEFT)
    {
        if(side==P1)
        {
            if(pos[i-1][j-1]==' ' || pos[i-1][j-1]=='b' || pos[i-1][j-1]=='q')
            {

                if(pos[i-1][j-1]=='q' ||  pos[i-1][j-1]=='b')
                    {
                        return 1;
                    }
                else
                    return king_check(i-1,j-1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i-1][j-1]==' ' || pos[i-1][j-1]=='B' || pos[i-1][j-1]=='Q')
            {

                if(pos[i-1][j-1]=='Q' || pos[i-1][j-1]=='B')
                   {
                        return 1;
                    }
                else
                    return king_check(i-1,j-1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
    else if(dir==TOP_LEFT)
    {
        if(side==P1)
        {
            if(pos[i+1][j-1]==' ' || pos[i+1][j-1]=='b' || pos[i+1][j-1]=='q')
            {

                if(pos[i+1][j-1]=='b' || pos[i+1][j-1]=='q')
                    {
                        return 1;
                    }
                else
                    return king_check(i+1,j-1,I,J,pos,side,dir);
            }
            else
                return king_check(I,J,I,J,pos,side,dir+1);
        }
        else if(side==P2)
        {
            if(pos[i+1][j-1]==' ' || pos[i+1][j-1]=='B' || pos[i+1][j-1]=='Q')
            {

                if(pos[i+1][j-1]=='B' || pos[i+1][j-1]=='Q')
                    {
                        return 1;
                    }
                else
                    return king_check(i+1,j-1,I,J,pos,side,dir);
            }
            else
               return king_check(I,J,I,J,pos,side,dir+1);
        }
    }
else if(dir>8)//TOP_RIGHT2,TOP_RIGHT1,BOTTOM_RIGHT1,BOTTOM_RIGHT2,BOTTOM_LEFT2,BOTTOM_LEFT1,TOP_LEFT1,TOP_LEFT2
{
    if(dir==TOP_RIGHT2 )
        {
           // printf(" %d %d",i,j);
        if(pos[i+2][j+1]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i+2][j+1]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
    else  if(dir==TOP_RIGHT1)
        {
             //printf(" %d %d",i,j);
        if(pos[i+1][j+2]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i+1][j+2]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
     else  if(dir==BOTTOM_RIGHT1)
        {
        if(pos[i-1][j+2]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i-1][j+2]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
     else  if(dir==BOTTOM_RIGHT2)
        {
        if(pos[i-2][j+1]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i-2][j+1]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
     else  if(dir==BOTTOM_LEFT2)
        {
        if(pos[i-2][j-1]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i-2][j-1]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
     else  if(dir==BOTTOM_LEFT1)
        {
        if(pos[i-1][j-2]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i-1][j-2]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
     else  if(dir==TOP_LEFT1)
        {
        if(pos[i+1][j-2]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i+1][j-2]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
     else  if(dir==TOP_LEFT2)
        {
            //printf("%d %d",i,j);
        if(pos[i+2][j-1]=='n' && side==P1)
            {
                        return 1;
                    }
        else if(pos[i+2][j-1]=='N' && side==P2)
            {
                        return 1;
                    }
        else
            return king_check(I,J,I,J,pos,side,dir+1);
        }
        else
            return 0;
}
return 0;

}
int check(char pos[][9])
{
    int i,j,i1,j1,side=0,a=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(pos[i][j]=='K')
            {
                side=P1;
                a= king_check(i,j,i,j,pos,side,1);
                for(i1=0;i1<3;i1++)
                {
                    for(j1=0;j1<3;j1++)
                    {
                        if(pos[i-1+i1][j-1+j1]==1)
                            a= a && king_check(i-1+i1,j-1+j1,i-1+i1,j-1+j1,pos,side,1);
                    }
                }
                if(a==1)
                    return 2;
                 else if(king_check(i,j,i,j,pos,side,1)==1)
                    return 1;
                /*
                if(king_check(i,j,i,j,pos,side,1) &&
                ((king_check(i+1,j-1,i+1,j-1,pos,side,1)==1)  && pos[i+1][j-1]==1) &&
                ((king_check(i+1,j,i+1,j,pos,side,1)==1)      && pos[i+1][j]==1)   &&
                ((king_check(i+1,j+1,i+1,j+1,pos,side,1)==1) && pos[i+1][j+1]==1) &&
                ((king_check(i,j+1,i,j+1,pos,side,1)==1)     && pos[i][j+1]==1)   &&
                ((king_check(i-1,j+1,i-1,j+1,pos,side,1)==1) && pos[i-1][j+1]==1) &&
                ((king_check(i-1,j,i-1,j,pos,side,1)==1)     && pos[i-1][j]==1)   &&
                ((king_check(i-1,j-1,i-1,j-1,pos,side,1)==1) && pos[i-1][j-1]==1) &&
                ((king_check(i,j-1,i,j-1,pos,side,1)==1)     && pos[i][j-1]==1))
                    return 2;*/

            }
            else if(pos[i][j]=='k')
            {
                side=P2;
                a=king_check(i,j,i,j,pos,side,1);
                for(i1=0;i1<3;i1++)
                {
                    for(j1=0;j1<3;j1++)
                    {
                        //printf("%c",pos[i-1+i1][j-1+j1]);
                        if(pos[i-1+i1][j-1+j1]==' ' )
                           {
                             a=(a && king_check(i-1+i1,j-1+j1,i-1+i1,j-1+j1,pos,side,1));
                           // printf("\nh %d",a);
                           }

                    }
                    printf("\n");
                }
                if(a==1)
                    return 3;
                 else if(king_check(i,j,i,j,pos,side,1)==1)
                    return 1;
                /* if(king_check(i,j,i,j,pos,side,1) &&
                ((king_check(i+1,j-1,i+1,j-1,pos,side,1)==1)  && pos[i+1][j-1]==1) &&
                ((king_check(i+1,j,i+1,j,pos,side,1)==1)      && pos[i+1][j]==1)   &&
                ((king_check(i+1,j+1,i+1,j+1,pos,side,1)==1) && pos[i+1][j+1]==1) &&
                ((king_check(i,j+1,i,j+1,pos,side,1)==1)     && pos[i][j+1]==1)   &&
                ((king_check(i-1,j+1,i-1,j+1,pos,side,1)==1) && pos[i-1][j+1]==1) &&
                ((king_check(i-1,j,i-1,j,pos,side,1)==1)     && pos[i-1][j]==1)   &&
                ((king_check(i-1,j-1,i-1,j-1,pos,side,1)==1) && pos[i-1][j-1]==1) &&
                ((king_check(i,j-1,i,j-1,pos,side,1)==1)     && pos[i][j-1]==1))
                    return 2;
                if(king_check(i,j,i,j,pos,side,1)==1)
                    return 1;*/
            }
        }
    }
return 0;
}
int checkmate(char pos[][9])
{
if(check(pos)==1)
    printf("\t\t\tCheck!!\n");
else if(check(pos)==2)
    {
        printf("\t\t\tCheckmate!!\n\t\t\tBlack wins");return 1;
    }
else if(check(pos)==3)
{
  printf("\t\t\tCheckmate!!\n\t\t\tWhite wins");return 1;
}
return 0;
}
int main()
{
    int i,j,c=-1,From[2],To[2],S,l1=0,l2=0;
    char pos[8][9]={"RNBQKBNR","PPPPPPPP","        ","        ","        ","        ","pppppppp","rnbqknbr"};
    char from[3],to[3];
    while(1)
    {   c++;
        printf("\n\t\t\t  A B C D E F G H\n");
        for(i=7;i>=0;i--)
        {
            printf("\t\t\t%d ",i+1);
            for(j=0;j<8;j++)
            {

                printf("%c ",pos[i][j]);
            }

            printf("\n\n");
        }
         printf("\t\t\t  A B C D E F G H\n");
        if(c%2==0)
            printf("\t\t\tWhite's turn:");
        else
            printf("\t\t\tBlack's turn:");
        scanf("%s%s",from,to);

        //printf("%d %d\n",((int)from[0]-48),((int)from[1]-64));
        //printf("%d %d\n",((int)to[0]-48),((int)to[1]-64));
        From[0]=((int)from[0]-48);
        From[1]=((int)from[1]-64);
        To[0]=((int)to[0]-48);
        To[1]=((int)to[1]-64);
        if(c%2==0)
        {
            if(!((int)pos[From[0]-1][From[1]-1]>64 && (int)pos[From[0]-1][From[1]-1]<83))
               {    l1++;
                   if(l1==3)
                    break;
                 continue;
               }
        }
        else if(c%2!=0)
        {
           if(!((int)pos[From[0]-1][From[1]-1]>98 && (int)pos[From[0]-1][From[1]-1]<115))
               { l2++;
                 if(l2==3)
                    break;
                 continue;
               }
        }
        if(pos[From[0]-1][From[1]-1]=='R' || pos[From[0]-1][From[1]-1]=='r')
        {
             int dir=0;
            if(To[0]>From[0] && To[1]==From[1])
                dir=UP;
            else if(To[0]<From[0] && To[1]==From[1])
                dir=DOWN;
            else if(To[1]>From[1] && To[0]==From[0])
                dir=RIGHT;
            else if(To[1]<From[1]  && To[0]==From[0])
                dir=LEFT;
            else;
            if(pos[From[0]-1][From[1]-1]=='R' && !(pos[To[0]-1][To[1]-1]>65 && pos[To[0]-1][To[1]-1]<83 ))
            {

                if((rook_verify(To,From)==1 ) && rook_obstacle(To,From[0],From[1],pos,dir))
                {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                }
            }
            else if(pos[From[0]-1][From[1]-1]=='r' && !(pos[To[0]-1][To[1]-1]> 97 && pos[To[0]-1][To[1]-1]<115 ))
            {
                 if((rook_verify(To,From)==1) && rook_obstacle(To,From[0],From[1],pos,dir))
                {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                }
            }
        }
        else if(pos[From[0]-1][From[1]-1]=='N' || pos[From[0]-1][From[1]-1]=='n')
        {

            if(pos[From[0]-1][From[1]-1]=='N' && !(pos[To[0]-1][To[1]-1]>65 && pos[To[0]-1][To[1]-1]<83 ))
            {
                if(knight_verify(To,From)==1)
                {

                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                }
            }
            else if(pos[From[0]-1][From[1]-1]=='n' && !(pos[To[0]-1][To[1]-1]> 97 && pos[To[0]-1][To[1]-1]<115 ))
            {
              if(knight_verify(To,From)==1 )
                {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                }
            }
        }
        else if(pos[From[0]-1][From[1]-1]=='B' || pos[From[0]-1][From[1]-1]=='b')
        {
            int dir;
            if(To[0]>From[0] && To[1]>From[1])
                dir=TOP_RIGHT;
            else if(To[0]>From[0] && To[1]<From[1])
                dir=TOP_LEFT;
            else if(To[1]>From[1] && To[0]<From[0])
                dir=BOTTOM_RIGHT;
            else if(To[1]<From[1] && To[0]<From[0])
                dir=BOTTOM_LEFT;
            else;
            if(pos[From[0]-1][From[1]-1]=='B' && !(pos[To[0]-1][To[1]-1]>65 && pos[To[0]-1][To[1]-1]<83 ))
                {
                    if((bishop_verify(To,From)==1) && bishop_obstacle(To,From[0],From[1],pos,dir))
                    {
                        pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                        pos[From[0]-1][From[1]-1]=' ';
                    }
                }
            else if(pos[From[0]-1][From[1]-1]=='b' && !(pos[To[0]-1][To[1]-1]> 97 && pos[To[0]-1][To[1]-1]<115 ))
            {
                if((bishop_verify(To,From)==1) && bishop_obstacle(To,From[0],From[1],pos,dir))
                    {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                    }
            }
        }
        else if(pos[From[0]-1][From[1]-1]=='Q' || pos[From[0]-1][From[1]-1]=='q')
        {
            int dir;
            if(To[0]>From[0] && To[1]==From[1])
                dir=UP;
            else if(To[0]<From[0] && To[1]==From[1])
                dir=DOWN;
            else if(To[1]>From[1] && To[0]==From[0])
                dir=RIGHT;
            else if(To[1]<From[1]  && To[0]==From[0])
                dir=LEFT;
            else  if(To[0]>From[0] && To[1]>From[1])
                dir=TOP_RIGHT;
            else if(To[0]>From[0] && To[1]<From[1])
                dir=TOP_LEFT;
            else if(To[1]>From[1] && To[0]<From[0])
                dir=BOTTOM_RIGHT;
            else if(To[1]<From[1] && To[0]<From[0])
                dir=BOTTOM_LEFT;
            else;
            if(pos[From[0]-1][From[1]-1]=='Q' && !(pos[To[0]-1][To[1]-1]>65 && pos[To[0]-1][To[1]-1]<83 ))
            {
                if(((queen_verify(To,From)==1 )) &&  (queen_obstacle(To,From[0],From[1],pos,dir)))
                {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]= ' ';
                }
            }
            else if(pos[From[0]-1][From[1]-1]=='q' && !(pos[To[0]-1][To[1]-1]> 97 && pos[To[0]-1][To[1]-1]<115 ))
            {
               if((queen_verify(To,From)==1 ) && queen_obstacle(To,From[0],From[1],pos,dir))
                {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                }
            }
        }
        else if(pos[From[0]-1][From[1]-1]=='K' || pos[From[0]-1][From[1]-1]=='k')
        {
            if(pos[From[0]-1][From[1]-1]=='K' && !(pos[To[0]-1][To[1]-1]>65 && pos[To[0]-1][To[1]-1]<83 ))
                {
                if(king_verify(To,From)==1)                    {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                    }
                 if(To[0]==From[0] && ((To[1]-From[1]==2)||(To[1]-From[1]==3)))
                    {
                        for(i=0;i<5;i++)
                            {
                            if((pos[From[0]-1][From[1]-1+i]==' ' || (pos[From[0]-1][From[1]-1+i]=='R')))
                                {
                                    if(pos[From[0]-1][From[1]-1+i]=='R')
                                        {
                                        pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                                        pos[From[0]-1][5]=pos[From[0]-1][From[1]-1+i];
                                        pos[From[0]-1][From[1]-1]=' ';
                                        pos[From[0]-1][From[1]-1+i]=' ';
                                        break;
                                        }
                                }
                            }
                    }
                else if(To[0]==From[0] && ((From[1]-To[1]==2)||(From[1]-To[1]==3)))
                    {
                        for(i=0;i<5;i++)
                            {
                            if(pos[From[0]-1][From[1]-1-i]==' ' || (pos[From[0]-1][From[1]-1-i]=='R'))
                                {
                                    if(pos[From[0]-1][From[1]-1-i]=='R')
                                        {
                                        pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                                        pos[From[0]-1][3]=pos[From[0]-1][From[1]-1-i];
                                        pos[From[0]-1][From[1]-1]= ' ';
                                        pos[From[0]-1][From[1]-1-i]=' ';
                                        break;
                                        }
                                }
                            }
                    }
                }
            else if(pos[From[0]-1][From[1]-1]=='k' && !(pos[To[0]-1][To[1]-1]> 97 && pos[To[0]-1][To[1]-1]<115 ))
                {
                if(king_verify(To,From)==1)// && king_obstacle(To,From,pos) )
                    {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                    }
                if(To[0]==From[0] && ((To[1]-From[1]==2)||(To[1]-From[1]==3)))
                    {
                        for(i=0;i<5;i++)
                            {
                            if(pos[From[0]-1][From[1]-1+i]==' ' || (pos[From[0]-1][From[1]-1+i]=='r'))
                                {
                                    if(pos[From[0]-1][From[1]-1+i]=='r')
                                        {
                                        pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                                        pos[From[0]-1][5]=pos[From[0]-1][From[1]-1+i];
                                        pos[From[0]-1][From[1]-1]= ' ';
                                        pos[From[0]-1][From[1]-1+i]=' ';
                                        break;
                                        }
                                }
                            }
                    }
                else if(To[0]==From[0] && ((From[1]-To[1]==2)||(From[1]-To[1]==3)))
                    {
                        for(i=0;i<5;i++)
                            {
                            if(pos[From[0]-1][From[1]-1-i]=='1' || (pos[From[0]-1][From[1]-1-i]=='r'))
                                {
                                    if(pos[From[0]-1][From[1]-1-i]=='r')
                                        {
                                        pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                                        pos[From[0]-1][3]=pos[From[0]-1][From[1]-1-i];
                                        pos[From[0]-1][From[1]-1]=' ';
                                        pos[From[0]-1][From[1]-1-i]=' ';
                                        break;
                                        }
                                }
                            }
                    }

                }
        }
        else if(pos[From[0]-1][From[1]-1]=='P' || pos[From[0]-1][From[1]-1]=='p')
        {
            if(pos[From[0]-1][From[1]-1]=='P' && !(pos[To[0]-1][To[1]-1]>65 && pos[To[0]-1][To[1]-1]<83 ))
                {
                if(pawn_verify(To,From,pos)==1)// && pawn_obstacle(To,From,pos))
                    {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                    }
                }
            else if(pos[From[0]-1][From[1]-1]=='p' && !(pos[To[0]-1][To[1]-1]> 97 && pos[To[0]-1][To[1]-1]<115 ))
                {
                if(pawn_verify(To,From,pos)==1)// && pawn_obstacle(To,From,pos))
                    {
                    pos[To[0]-1][To[1]-1]=pos[From[0]-1][From[1]-1];
                    pos[From[0]-1][From[1]-1]=' ';
                    }
                }
        }
        if(checkmate(pos)==1)
            break;
        S=check(pos);
    }

return 0;
}
