#pragma once

class Memory {
public:
   int winner;

   static Memory& GetInstance()
   {
	   static Memory instance; // 初回呼び出し時に1回だけ初期化
	   return instance;
   }
};