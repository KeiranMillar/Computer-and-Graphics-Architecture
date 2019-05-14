#include <stdint.h>
#include "gba.h"
//c:\gba700\RunMake "$(CURRENT_DIRECTORY)" run
//c:\gba700\RunMake "$(CURRENT_DIRECTORY)" clean
	int score = 0;
	
	int map1[16][24]=
	{
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1},
	{1,0,1,2,0,0,1,0,0,1,1,1,0,1,0,1,2,1,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,1,1,1,1,1},
	{1,0,0,0,1,2,0,1,1,0,0,1,0,0,0,1,0,1,0,1,2,1,2,1},	
	{1,0,0,0,1,1,0,1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1},	
	{1,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
	{1,1,1,0,2,0,1,1,0,0,1,0,0,1,0,0,0,1,1,1,0,0,0,1},
	{1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,0,1},
	{1,0,0,0,0,1,0,0,1,0,1,0,0,0,2,1,0,0,0,0,0,0,0,1},
	{1,0,0,1,1,1,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,2,1,2,0,0,0,0,0,0,0,2,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}};
	
	int map2[16][24]=
	{
	{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,1,2,2,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,2,1,0,0,0,1,1,0,0,0,1,0,1},
	{1,0,1,2,0,0,0,0,1,0,0,0,1,0,1,0,1,1,0,0,0,1,0,1},
	{1,0,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,2,1,2,1},
	{1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1},
	{1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,2,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1},
	{1,0,1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,1,0,1,1,1,0,1},
	{1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1},
	{1,0,1,2,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1},
	{1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}};
	
	//This clears the area where the score is displayed
	void Clear_Bar()
	{
		for(int x = 67; x < 78;x++)
		{
			for(int y = 145; y < 150; y++)
			{
				PlotPixel8(x,y,RGB(0,0,0));
			}	
		}
		
	}
	
	//This draws the word SCORE
	void Draw_Text()
	{
	const int SLetter[5][5]=
	{
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1},
	{0,0,0,0,1},
	{1,1,1,1,1}
	};
	const int CLetter[5][5]=
	{
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,1,1,1,1}
	};
	const int OLetter[5][5]=
	{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
	};
	const int RLetter[5][5]=
	{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,1,1,1,1},
	{1,0,1,1,0},
	{1,0,0,1,1}
	};
	const int ELetter[5][5]=
	{
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1}
	};
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(SLetter[i][j] == 1)
				{
					PlotPixel8(35 + j, 145 + i, 1);
				}
				if(CLetter[i][j] == 1)
				{
					PlotPixel8(41 + j, 145 + i, 1);
				}
				if(OLetter[i][j] == 1)
				{
					PlotPixel8(47 + j, 145 + i, 1);
				}
				if(RLetter[i][j] == 1)
				{
					PlotPixel8(53 + j, 145 + i, 1);
				}
				if(ELetter[i][j] == 1)
				{
					PlotPixel8(59 + j, 145 + i, 1);
				}
				PlotPixel8(65, 146, 1);
				PlotPixel8(65, 148, 1);

			}
		}
	}
	
	//This function draws the pellet black if you collect it so there isn't half a pellet left when you collect it
	void Remove_Pellet(int x, int y)
	{
		for(int i = 4; i < 6; i++)
		{
			for(int j = 4; j < 6; j++)
			{
				FlipBuffers();
				PlotPixel8(i+(x*10), j+(y*10), 0);
				FlipBuffers();
				PlotPixel8(i+(x*10), j+(y*10), 0);
			}
		}
	}
	
	//This function displays the text when you win the game
	void You_Win()
	{
	const int YLetter[5][5]=
	{
	{1,0,0,0,1},
	{0,1,0,1,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0}
	};
	const int OLetter[5][5]=
	{
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
	};
	const int ULetter[5][5]=
	{
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
	};
	
	const int WLetter[5][5]=
	{
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,1,0,1},
	{1,1,0,1,1},
	{1,0,0,0,1}
	};
	const int ILetter[5][5]=
	{
	{1,1,1,1,1},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,1,1,1}
	};
	const int NLetter[5][5]=
	{
	{1,1,0,0,1},
	{1,1,0,0,1},
	{1,0,1,0,1},
	{1,0,0,1,1},
	{1,0,0,1,1}
	};
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5 ; j++)
		{
			if(YLetter[i][j] == 1)
			{
				PlotPixel8(102 + j, 75 + i, 2);
			}
			if(OLetter[i][j] == 1)
			{
				PlotPixel8(108 + j, 75 + i, 2);
			}
			if(ULetter[i][j] == 1)
			{
				PlotPixel8(114 + j, 75 + i, 2);
			}
			if(WLetter[i][j] == 1)
			{
				PlotPixel8(122 + j, 75 + i, 2);
			}
			if(ILetter[i][j] == 1)
			{
				PlotPixel8(128 + j, 75 + i, 2);
			}
			if(NLetter[i][j] == 1)
			{
				PlotPixel8(134 + j, 75 + i, 2);
			}
			}
		}
	FlipBuffers();
	}
	
	//This case statement draws the numbers for the score
	void Draw_Score()
	{
		Clear_Bar();
		const int Num0[5][5]=
		{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
		};
		const int Num1[5][5]=
		{
		{0,1,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{1,1,1,1,1}
		};
		const int Num2[5][5]=
		{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{0,0,0,1,0},
		{0,1,1,0,0},
		{1,1,1,1,1}
		};
		const int Num3[5][5]=
		{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{0,0,1,1,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
		};
		const int Num4[5][5]=
		{
		{1,0,0,1,0},
		{1,0,0,1,0},
		{1,1,1,1,1},
		{0,0,0,1,0},
		{0,0,0,1,0}
		};
		const int Num5[5][5]=
		{
		{1,1,1,1,1},
		{1,0,0,0,0},
		{1,1,1,1,0},
		{0,0,0,0,1},
		{1,1,1,1,0}
		};
		const int Num6[5][5]=
		{
		{0,1,1,0,0},
		{1,0,0,0,0},
		{1,1,1,1,0},
		{1,0,0,0,1},
		{0,1,1,1,0}
		};
		const int Num7[5][5]=
		{
		{1,1,1,1,1},
		{0,0,0,1,1},
		{0,0,1,1,0},
		{0,1,1,0,0},
		{1,1,0,0,0}
		};
		const int Num8[5][5]=
		{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
		};
		const int Num9[5][5]=
		{
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,1,1,1,1},
		{0,0,0,0,1},
		{0,0,0,0,1}
		};
		switch (score)
		{
		case 0 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num0[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
			}
		}			; break;
		case 10 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
			}
		} ; break;
		case 20 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num2[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
			}
		}; break;
		case 30 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num3[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 40 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num4[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
			}
		}; break;
		case 50 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num5[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 60 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num6[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 70 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num7[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 80 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num8[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 90 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num9[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 100 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 110 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num1[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 120 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num2[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 130 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num3[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 140 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num4[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 150 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num5[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 160 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num6[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 170 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num7[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 180 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num8[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 190 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num1[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num9[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		case 200 : for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5 ; j++)
			{
				if(Num2[i][j] == 1)
				{
					PlotPixel8(67 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(73 + j, 145 + i, 1);
				}
				if(Num0[i][j] == 1)
				{
					PlotPixel8(79 + j, 145 + i, 1);
				} 
			}
		}; break;
		}
	}
	
	void Draw_Player(int x, int y)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				PlotPixel8(x+i, y+j, 1);
			}
		}
		FlipBuffers();
	}
	
	//This draws the player black to allow another player to be drawn in another position
	void Remove_Player(int x, int y)
	{
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				PlotPixel8(i+x, j+y, 0);
			}
		}
	}
	
	//This draws a 10x10 block when there is a 1 in the map array
	void Draw_Block(int x, int y)
	{
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				PlotPixel8(i+x, j+y, 3);
			}
		}
	}
	
	//This draws a 2x2 block when there is a 2 in the map array
	void Draw_Pellet(int x, int y)
	{
		for(int i = 4; i < 6; i++)
		{
			for(int j = 4; j < 6; j++)
			{
				PlotPixel8(i+x, j+y, 1);
			}
		}
	}	
	
	void Draw_Map()
	{
		for(int i = 0; i < 24; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				if (map1[j][i] == 1)
				{
					Draw_Block((i*10),(j*10));
				}
				if (map1[j][i] == 2)
				{
					Draw_Pellet((i*10),(j*10));
				}
			}
		}
	}
	
	void Draw_Map2()
	{
		for(int i = 0; i < 24; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				if (map2[j][i] == 1)
				{
					Draw_Block((i*10),(j*10));
				}
				if (map2[j][i] == 2)
				{
					Draw_Pellet((i*10),(j*10));
				}
			}
		}
	}
	
	//This is the main game loop for level 2
	bool Level2()
	{
	int playerX = 13;
	int playerY = 13;
	
	FlipBuffers();
	Draw_Score();
	Draw_Map2();
	Draw_Text();
	FlipBuffers();
	Draw_Score();
	Draw_Map2();
	Draw_Text();
	
	bool Won = false;
	bool doorOpen = false;
	do
	{
	FlipBuffers();
	Remove_Player(playerX, playerY);
	uint16_t currentKeys = REG_KEYINPUT;
	if ((currentKeys & KEY_UP) == 0)
	{
		playerY--;
		if(map2[playerY/10][playerX/10] == 1 || map2[playerY/10][((playerX + 3)/10)] == 1)
		{
			playerY += 4;
		}
	}
	else if ((currentKeys & KEY_DOWN) == 0)
	{
		playerY++;
	 	if(map2[((playerY+3)/10)][((playerX + 3)/10)] == 1 || map2[((playerY+3)/10)][(playerX/10)] == 1)
		{
			playerY -= 4;
		}
	}
	else if ((currentKeys & KEY_LEFT) == 0)
	{
		playerX--;
	 	if(map2[(playerY/10)][(playerX/10)] == 1 || map2[((playerY+3)/10)][(playerX/10)] == 1)
		{
			playerX += 4;
		}
	}
	else if ((currentKeys & KEY_RIGHT) == 0)
	{
		playerX++;
	 	if(map2[((playerY+3)/10)][((playerX+3)/10)] == 1 || map2[(playerY/10)][((playerX+3)/10)] == 1)
		{
			playerX -= 4;
		}
	}
	if(map2[((playerY+3)/10)][((playerX + 3)/10)] == 2 && map2[playerY/10][(playerX + 3)/10] == 2 && map2[playerY/10][playerX/10] == 2 && map2[(playerY + 3)/10][playerX/10] == 2)
	{
		map2[(playerY/10)][(playerX/10)] = 0;
		score = score + 10;
		Remove_Pellet((playerX/10), (playerY/10));
	}

	if (playerX > 236) 
	{
		playerX = 236;
	}
	if (playerX < 0) 
	{
		playerX = 0;
	}
	if (playerY < 0) 
	{
		playerY = 0;
	}
	if (playerY > 136) 
	{
		playerY = 136;
	}
	
	Draw_Score();
	
	if(playerX >= 11 && playerX <= 20 && playerY >= 0 && playerY <= 10)
	{
		ClearScreen8(0);
		return false;
	}
	
	if(playerX >= 219 && playerX <= 229 && playerY >= 130 && playerY <= 140)
	{
		ClearScreen8(0);
		return true;
	}

	if(doorOpen == false)
	{
		if (score == 200)
		{
			map2[12][21]=0;
			ClearScreen8(0);
			Draw_Map2();
			Draw_Text();
			doorOpen = true;
		}
	}
	Draw_Player(playerX, playerY);
	WaitVSync();
	}while(Won != true);
	ClearScreen8(0);
	return false;
	}
	
	//This is the main game loop for level 1
	void Level1(int playerX, int playerY)
	{
	
	FlipBuffers();
	Draw_Score();
	Draw_Map();
	Draw_Text();
	FlipBuffers();
	Draw_Score();
	Draw_Map();
	Draw_Text();
	
	bool Won = false;
	
	do
	{
		FlipBuffers();
		Remove_Player(playerX, playerY);
		uint16_t currentKeys = REG_KEYINPUT;
		if ((currentKeys & KEY_UP) == 0)
		{
			playerY--;
			if(map1[playerY/10][playerX/10] == 1 || map1[playerY/10][((playerX + 3)/10)] == 1)
			{
				playerY += 4;
			}
		}
		else if ((currentKeys & KEY_DOWN) == 0)
		{
			playerY++;
			if(map1[((playerY+3)/10)][((playerX + 3)/10)] == 1 || map1[((playerY+3)/10)][(playerX/10)] == 1)
			{
				playerY -= 4;
			}
		}
		else if ((currentKeys & KEY_LEFT) == 0)
		{
			playerX--;
			if(map1[(playerY/10)][(playerX/10)] == 1 || map1[((playerY+3)/10)][(playerX/10)] == 1)
			{
				playerX += 4;
			}
		}
		else if ((currentKeys & KEY_RIGHT) == 0)
		{
			playerX++;
			if(map1[((playerY+3)/10)][((playerX+3)/10)] == 1 || map1[(playerY/10)][((playerX+3)/10)] == 1)
			{
				playerX -= 4;
			}
		}
		if(map1[((playerY+3)/10)][((playerX + 3)/10)] == 2 && map1[playerY/10][(playerX + 3)/10] == 2 && map1[playerY/10][playerX/10] == 2 && map1[(playerY + 3)/10][playerX/10] == 2)
		{
			map1[(playerY/10)][(playerX/10)] = 0;
			score = score + 10;
			Remove_Pellet((playerX/10), (playerY/10));
		}

		if (playerX > 236) 
		{
			playerX = 236;
		}
		if (playerX < 0) 
		{
			playerX = 0;
		}
		if (playerY < 0) 
		{
			playerY = 0;
		}
		if (playerY > 136) 
		{
			playerY = 136;
		}
		Draw_Score();
		if(playerX >= 219 && playerX <= 229 && playerY >= 130 && playerY <= 140)
		{
			Won = true;
			ClearScreen8(0);
		}
		Draw_Player(playerX, playerY);
		WaitVSync();
	}while(Won != true);
	ClearScreen8(0);
	FlipBuffers();
	ClearScreen8(0);
	
	if (score == 200)
	{
	map2[12][21]=0;
	}
	return;
	}
	
// The entry point for the game
int main()
{
    // Put the display into bitmap mode 4, and enable background 2.
	REG_DISPCNT = MODE4 | BG2_ENABLE;
	
	
    // 	Define some colours
	SetPaletteBG(0, RGB(0, 0, 0)); //Black
	SetPaletteBG(1, RGB(31, 0, 0)); //Red
	SetPaletteBG(2, RGB(0, 31, 31)); //Cyan
	SetPaletteBG(3, RGB(31, 31, 31)); //White
	
	// … initialisation
	bool won = false;
	int startingX = 13;
	int startingY = 3;
	while (true)
	{
	do
	{
	Level1(startingX, startingY);
	
	won = Level2();
	startingX = 223;
	startingY = 124;
	}while(won != true);
	break;
	}
	
	ClearScreen8(0);
	You_Win();

	//This pauses the game to allow the user to read you win
	for(int i = 0; i<20;i++)
	{
	WaitVSync();
	}
	
	return 0;
}
