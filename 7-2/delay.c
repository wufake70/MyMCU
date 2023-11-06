
void delay(unsigned int xms)
{
	while(xms)
	{
			unsigned char x,y,z;

	x=1;
	y=2;
	z=2;
	do
		{
			do
			{
				while(--z);
			}
			while(--y);
		}
		while(--x);
	xms=xms-1;}	
}