#pragma once

class Memory {
public:
   int winner;

   static Memory& GetInstance()
   {
	   static Memory instance; // ����Ăяo������1�񂾂�������
	   return instance;
   }
};