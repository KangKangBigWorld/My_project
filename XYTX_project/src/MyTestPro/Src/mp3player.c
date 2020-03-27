#include "mp3player.h"
#include "ff.h"
#include "vs10xx.h"
#include "spi.h"
#include "led.h"
#include "tftlcd.h" 
#include "My_Function.h"

uint8_t MP3_Volume;
/****************************************************************************
* Function Name  : MP3_Init
* Description    : 初始化MP3
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

int8_t MP3_Init(void)
{
    uint16_t id;
	VS10XX_Config();        //GPIO和SPI初始化
    id = VS10XX_RAM_Test();	
	if(id != 0x83FF)        //检测存储器测试的结果
	{	
		return 0xFF;
	}
	VS10XX_SineTest();     //正弦测试
	MP3_BaseSetting(0,0,0,0);               //基本设置
	MP3_EffectSetting(0);                   //音效设置

	return 0;
}                                 

/****************************************************************************
* Function Name  : MP3_AudioSetting
* Description    : 设置声音的大小，设置SCI_VOL寄存器
* Input          : vol：声音的大小（0~0xFF）
* Output         : None
* Return         : None
****************************************************************************/

void MP3_AudioSetting(uint8_t vol)
{
	uint16_t volValue = 0;
	
	/* 0是最大音量，0xFE是无声，低8字节控制右通道，高8字节控制左通道 */
	vol = 254 - vol;
	volValue = vol | (vol << 8);

	VS10XX_WriteCmd(SCI_VOL, volValue);
}

/****************************************************************************
* Function Name  : MP3_BaseSetting
* Description    : 基本设置：设置SCI_BASS寄存器
* Input          : amplitudeH：高频增益 0~15(单位:1.5dB,小于9的时候为负数)
*                * freqLimitH：高频上限 2~15(单位:10Hz)
*                * amplitudeL：低频增益 0~15(单位:1dB)
*                * freqLimitL：低频下限 1~15(单位:1Khz)
* Output         : None
* Return         : None
****************************************************************************/

void MP3_BaseSetting(
	uint8_t amplitudeH, uint8_t freqLimitH,
	uint8_t amplitudeL, uint8_t freqLimitL
)
{
	uint16_t bassValue = 0;
	
	/* 高频增益是12 ：15位 */
	bassValue = amplitudeH & 0x0F;
	bassValue <<= 4;
	
	/* 频率下限是 11 ：8位 */
	bassValue |= freqLimitL & 0x0F;
	bassValue <<= 4;
	
	/* 低频增益是 7 ：4 位 */
	bassValue |= amplitudeL & 0x0F;
	bassValue <<= 4;
	
	/* 频率上限是 3 ： 0位 */
	bassValue |= freqLimitH & 0x0F;
	
	VS10XX_WriteCmd(SCI_BASS, bassValue); 
		
}

/****************************************************************************
* Function Name  : MP3_EffectSetting
* Description    : 音效设置。设置SCI_MODE寄存器
* Input          : effect：0,关闭;1,最小;2,中等;3,最大。
* Output         : None
* Return         : None
****************************************************************************/

void MP3_EffectSetting(uint8_t effect)
{
	uint16_t effectValue;

	effectValue = VS10XX_ReadData(SCI_MODE);
	if(effect & 0x01)
	{
		effectValue |= 1 << 4;	
	}
	else
	{
		effectValue &= ~(1 << 5);
	}
	if(effect & 0x02)
	{
		effectValue |= 1 << 7;
	}
	else
	{
		effectValue &= ~(1 << 7);
	}

	VS10XX_WriteCmd(SCI_MODE, effectValue);
}

/****************************************************************************
* Function Name  : MP3_ShowVolume
* Description    : 显示音量
* Input          : value：显示的音量
* Output         : None
* Return         : None
****************************************************************************/

void MP3_ShowVolume(uint8_t value)
{
    uint8_t showData[4] = {0, 0, 0, 0};

    showData[0] = value % 1000 / 100 + '0';
    showData[1] = value % 100 / 10 + '0';
    showData[2] = value % 10 + '0';
		
		LCD_Fill(80,240,150,270,(u16)WHITE);//在指定区域内填充单个颜色
    LCD_ShowString(80,245,(char*)"音量",24,RED,WHITE);
    LCD_ShowString(120,245,(char*)showData,24,RED,WHITE);
    //LCD_ShowString("音量",80,245,,)
		//printf_All(80,245,"音量",(u16)BLACK);
		//printf_All(120,245,showData,(u16)BLACK);
		
}
/****************************************************************************
* Function Name  : MP3_PlaySong
* Description    : 播放一首歌曲
* Input          : addr：播放地址和歌名（歌曲名记得加.mp3后缀）
* Output         : None
* Return         : None
****************************************************************************/

extern u8 music_displayflag;
extern u8 music_courrID; 
extern u8 music_num;
extern u8 Cls_Flag;
extern u8 Current;

void MP3_PlaySong(uint8_t *addr)
{
	FIL file;
	UINT br;
	FRESULT res;
	uint8_t musicBuff[512]={0};
	uint16_t k=0;
  /*open file*/
	res = f_open(&file, (const TCHAR*)addr, FA_READ);
 	//led1=0;
	VS10XX_SoftReset();
	//led2=0;
	if(res == FR_OK)
	{
		u8 exit=0;
		while(1)
		{
			res = f_read(&file, musicBuff, sizeof(musicBuff), &br);
			k = 0;
			
      TOUCH_Scan();
			if(Touch_iFlag==1)
				{
					if(((TouchData.lcdx>=190)&&(TouchData.lcdx<=239))&&((TouchData.lcdy>=0)&&(TouchData.lcdy<=70)))
					{
							MusicExit=1;
						  Busy("再次点击退出音乐！");
					}
					else if(((TouchData.lcdx<=48))&&((TouchData.lcdy>=0)&&(TouchData.lcdy<=53)))
					{
						My_MusicAdd();
					}
					else if(((TouchData.lcdx<=239))&&((TouchData.lcdy>=72)&&(TouchData.lcdy<=72+24*5)))
					{
						Select_MusicLine();
					}
					else if(((TouchData.lcdx>=120)&&(TouchData.lcdx<=239))&&((TouchData.lcdy>=194)&&(TouchData.lcdy<=234)))
					{
						Music_Delete();
					}
					else if(((TouchData.lcdx>=14)&&(TouchData.lcdx<=82))&&((TouchData.lcdy>=250)&&(TouchData.lcdy<=298)))
					{
						Music_Last();
					}
					else if(((TouchData.lcdx>=86)&&(TouchData.lcdx<=152))&&((TouchData.lcdy>=250)&&(TouchData.lcdy<=298)))
					{
						Music_Play();
					}
					else if(((TouchData.lcdx>=158)&&(TouchData.lcdx<=216))&&((TouchData.lcdy>=250)&&(TouchData.lcdy<=298)))
					{
						Music_Next();
					}
					else if(((TouchData.lcdx>=0)&&(TouchData.lcdx<=239))&&((TouchData.lcdy>=331)&&(TouchData.lcdy<=370)))
					{
						Music_Volume();
					}
					Touch_iFlag=0;
				}
			
			if(MusicExit==1)
			{
				Busy("音乐播放已停止");
				break;
			}
			if(MusicPlay==0)
			{
				Busy("音乐播放已暂停");
				continue;
			}
			Busy("正在播放音乐");
			do
			{	
					/* 发送歌曲信息 */
					if(VS10XX_SendMusicData(musicBuff+k) == 0)
					{
							k += 32;
					}
			}
			while(k < br);
			
			if (res || (br == 0))
			{
				MusicExit=1;
				Iocn(96,250,48,48,gImage_start,"播放",BLACK,WHITE);
				Busy("音乐播放已停止");
				break;    // error or eof 
			} 
		}
		f_close(&file);  //不论是打开，还是新建文件，一定记得关闭
	}		
}

	





