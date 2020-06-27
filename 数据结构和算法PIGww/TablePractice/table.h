//
//  table.h
//  DataStructure
//
//  Created by 官啸鹏 on 2020/6/22.
//  Copyright © 2020 PIGww. All rights reserved.
//

#ifndef table_h
#define table_h
void Drawfour(){
    cout<<"----";
}
void DrawRowLine(int bei){
    for(int i=0;i<bei;i++)Drawfour();
}
void DrawTable(int row,int col){
    for(int i=1;i<=row;i++){
        cout<<"-";
        for(int j=1;j<=col;j++)
        {
            cout<<"--------";
        }
        cout<<endl<<"|";
        for(int j=1;j<=col;j++)
        {
            cout<<"\t\t|";
        }
        cout<<endl;
    }
    for(int j=1;j<=col;j++)
    {
        cout<<"--------";
    }cout<<"-"<<endl;
}

#endif /* table_h */
