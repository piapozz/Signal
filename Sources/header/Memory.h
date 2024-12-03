#pragma once

class Memory {
public:
   int winner;

   static Memory& GetInstance()
   {
	   static Memory instance; // ‰‰ñŒÄ‚Ño‚µ‚É1‰ñ‚¾‚¯‰Šú‰»
	   return instance;
   }
};