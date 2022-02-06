#include <allegro.h>
#define ALTURA 320
#define LARGURA 320
#define DELAY_BOT 200
#define FREQ_GR 1000

// Abilitando o bot�o de fechar
volatile int exit_program = FALSE;
void fechar_programa()
{
	exit_program = TRUE;
}
END_OF_FUNCTION(fechar_programa);

int main()
{

	allegro_init();
	install_timer();
	install_mouse();
	install_keyboard();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGURA, ALTURA, 0, 0);
	set_window_title("Calculadora UPE");

	LOCK_VARIABLE(exit_program);
	LOCK_FUNCTION(fechar_programa);
	set_close_button_callback(fechar_programa);
	// SONS
	SAMPLE *punch = load_sample("EFEITOS/punch.wav");
	SAMPLE *resposta = load_sample("EFEITOS/respost.wav");
	SAMPLE *mais_de = load_sample("EFEITOS/oito.wav");
	MIDI *musica = load_midi("MUSICAS/musica.mid");

	// BITMAPS
	BITMAP *cursor = load_bitmap("SPRITES/cursor.bmp", NULL);
	BITMAP *buffer = create_bitmap(LARGURA, ALTURA);
	BITMAP *base = load_bitmap("SPRITES/CALC_BASE.bmp", NULL);
	BITMAP *boneco = load_bitmap("SPRITES/boneco.bmp", NULL);
	BITMAP *base_a = load_bitmap("SPRITES/BASE_CALC.bmp", NULL);
	// BITMAPS BOTOES
	BITMAP *um = load_bitmap("TECLAS/1.bmp", NULL);
	BITMAP *dois = load_bitmap("TECLAS/2.bmp", NULL);
	BITMAP *tres = load_bitmap("TECLAS/3.bmp", NULL);
	BITMAP *quatro = load_bitmap("TECLAS/4.bmp", NULL);
	BITMAP *cinco = load_bitmap("TECLAS/5.bmp", NULL);
	BITMAP *seis = load_bitmap("TECLAS/6.bmp", NULL);
	BITMAP *sete = load_bitmap("TECLAS/7.bmp", NULL);
	BITMAP *oito = load_bitmap("TECLAS/8.bmp", NULL);
	BITMAP *nove = load_bitmap("TECLAS/9.bmp", NULL);
	BITMAP *zero = load_bitmap("TECLAS/0.bmp", NULL);
	BITMAP *som = load_bitmap("TECLAS/+.bmp", NULL);
	BITMAP *sub = load_bitmap("TECLAS/-.bmp", NULL);
	BITMAP *mult = load_bitmap("TECLAS/mult.bmp", NULL);
	BITMAP *div = load_bitmap("TECLAS/div.bmp", NULL);
	BITMAP *igual = load_bitmap("TECLAS/=.bmp", NULL);
	BITMAP *clear = load_bitmap("TECLAS/clear.bmp", NULL);

	// VARIAVEIS
	float result = 0;
	int i = 0;
	int num1 = 0, num2 = 0;
	int op = 0, aux = 1;

	while (!exit_program)
	{

		if (key[KEY_R])
		{
			play_sample(punch, 255, 128, FREQ_GR, FALSE);
			num1 = 0;
			num2 = 0;
			result = 0;
			op = 0;
			aux = 1;
			rest(DELAY_BOT);
		}
		if (key[KEY_M])
		{
			if (i == 0)
			{
				play_midi(musica, TRUE);
				i = 1;
				rest(100);
			}
			else if (i == 1)
			{
				midi_pause();
				i = 2;
				rest(100);
			}
			else
			{
				midi_resume();
				i = 1;
				rest(100);
			}
		}
		if (aux == 1)
		{
			if (key[KEY_0] || key[KEY_0_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 0;
				rest(DELAY_BOT);
			}
			else if (key[KEY_1] || key[KEY_1_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 1;
				rest(DELAY_BOT);
			}
			else if (key[KEY_2] || key[KEY_2_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 2;
				rest(DELAY_BOT);
			}
			else if (key[KEY_3] || key[KEY_3_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 3;
				rest(DELAY_BOT);
			}
			else if (key[KEY_4] || key[KEY_4_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 4;
				rest(DELAY_BOT);
			}
			else if (key[KEY_5] || key[KEY_5_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 5;
				rest(DELAY_BOT);
			}
			else if (key[KEY_6] || key[KEY_6_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 6;
				rest(DELAY_BOT);
			}
			else if (key[KEY_7] || key[KEY_7_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 7;
				rest(DELAY_BOT);
			}
			else if (key[KEY_8] || key[KEY_8_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 8;
				rest(DELAY_BOT);
			}
			else if (key[KEY_9] || key[KEY_9_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = num1 * 10 + 9;
				rest(DELAY_BOT);
			}
		}
		else if (aux == 2)
		{
			if (key[KEY_0] || key[KEY_0_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 0;
				rest(DELAY_BOT);
			}
			else if (key[KEY_1] || key[KEY_1_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 1;
				rest(DELAY_BOT);
			}
			else if (key[KEY_2] || key[KEY_2_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 2;
				rest(DELAY_BOT);
			}
			else if (key[KEY_3] || key[KEY_3_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 3;
				rest(DELAY_BOT);
			}
			else if (key[KEY_4] || key[KEY_4_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 4;
				rest(DELAY_BOT);
			}
			else if (key[KEY_5] || key[KEY_5_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 5;
				rest(DELAY_BOT);
			}
			else if (key[KEY_6] || key[KEY_6_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 6;
				rest(DELAY_BOT);
			}
			else if (key[KEY_7] || key[KEY_7_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 7;
				rest(DELAY_BOT);
			}
			else if (key[KEY_8] || key[KEY_8_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 8;
				rest(DELAY_BOT);
			}
			else if (key[KEY_9] || key[KEY_9_PAD])
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num2 = num2 * 10 + 9;
				rest(DELAY_BOT);
			}
		}
		if (key[KEY_PLUS_PAD])
		{
			play_sample(punch, 255, 128, FREQ_GR, FALSE);
			op = 1;
			aux = 2;
			rest(DELAY_BOT);
		}
		if (key[KEY_MINUS_PAD])
		{
			play_sample(punch, 255, 128, FREQ_GR, FALSE);
			op = 2;
			aux = 2;
			rest(DELAY_BOT);
		}
		if (key[KEY_ASTERISK])
		{
			play_sample(punch, 255, 128, FREQ_GR, FALSE);
			op = 3;
			aux = 2;
			rest(DELAY_BOT);
		}
		if (key[KEY_SLASH_PAD])
		{
			play_sample(punch, 255, 128, FREQ_GR, FALSE);
			op = 4;
			aux = 2;
			rest(DELAY_BOT);
		}
		if ((key[KEY_ENTER] || key[KEY_ENTER_PAD]))
		{
			play_sample(punch, 255, 128, FREQ_GR, FALSE);
			if (aux != 1)
			{
				if (op == 1)
				{
					result = num1 + num2;
				}
				else if (op == 2)
				{
					result = num1 - num2;
				}
				else if (op == 3)
				{
					result = num1 * num2;
				}
				else if (op == 4)
				{
					result = num1 * 1.0 / num2;
				}
				aux = 3;
				play_sample(resposta, 255, 128, FREQ_GR, FALSE);
				rest(6000);
				if (result > 8000)
				{
					play_sample(mais_de, 255, 128, FREQ_GR, FALSE);
					rest(8000);
				}
			}
			rest(DELAY_BOT);
		}

		// DRAW

		draw_sprite(buffer, base_a, 0, 0);
		draw_sprite(buffer, base, 0, 0);

		// BOTOES
		if (mouse_x > 36 && mouse_x < (36 + 37) && mouse_y > 90 && mouse_y < (90 + 37))
		{
			draw_sprite(buffer, um, 36, 90);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 1;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 1;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 99 && mouse_x < (99 + 37) && mouse_y > 90 && mouse_y < (90 + 37))
		{
			draw_sprite(buffer, dois, 99, 90);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 2;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 2;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 162 && mouse_x < (162 + 37) && mouse_y > 90 && mouse_y < (90 + 37))
		{
			draw_sprite(buffer, tres, 162, 90);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 3;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 3;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 36 && mouse_x < (36 + 37) && mouse_y > 147 && mouse_y < (147 + 37))
		{
			draw_sprite(buffer, quatro, 36, 147);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 4;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 4;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 99 && mouse_x < (99 + 37) && mouse_y > 147 && mouse_y < (147 + 37))
		{
			draw_sprite(buffer, cinco, 99, 147);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 5;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 5;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 162 && mouse_x < (162 + 37) && mouse_y > 147 && mouse_y < (147 + 37))
		{
			draw_sprite(buffer, seis, 162, 147);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 6;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 6;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 36 && mouse_x < (36 + 37) && mouse_y > 206 && mouse_y < (206 + 37))
		{
			draw_sprite(buffer, sete, 36, 206);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 7;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 7;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 99 && mouse_x < (99 + 37) && mouse_y > 206 && mouse_y < (206 + 37))
		{
			draw_sprite(buffer, oito, 99, 206);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 8;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 8;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 161 && mouse_x < (161 + 37) && mouse_y > 206 && mouse_y < (206 + 37))
		{
			draw_sprite(buffer, nove, 161, 206);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10 + 9;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10 + 9;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 36 && mouse_x < (36 + 37) && mouse_y > 265 && mouse_y < (265 + 37))
		{
			draw_sprite(buffer, zero, 36, 265);
			if (mouse_b == 1)
			{
				if (aux == 1)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num1 = num1 * 10;
					rest(DELAY_BOT);
				}
				else if (aux == 2)
				{
					play_sample(punch, 255, 128, FREQ_GR, FALSE);
					num2 = num2 * 10;
					rest(DELAY_BOT);
				}
			}
		}
		if (mouse_x > 225 && mouse_x < (225 + 66) && mouse_y > 90 && mouse_y < (90 + 37))
		{
			draw_sprite(buffer, som, 225, 90);
			if (mouse_b == 1)
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				op = 1;
				aux = 2;
				rest(DELAY_BOT);
			}
		}
		if (mouse_x > 225 && mouse_x < (225 + 66) && mouse_y > 147 && mouse_y < (147 + 37))
		{
			draw_sprite(buffer, sub, 225, 147);
			if (mouse_b == 1)
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				op = 2;
				aux = 2;
				rest(DELAY_BOT);
			}
		}
		if (mouse_x > 224 && mouse_x < (224 + 66) && mouse_y > 265 && mouse_y < (265 + 37))
		{
			draw_sprite(buffer, div, 224, 265);
			if (mouse_b == 1)
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				op = 4;
				aux = 2;
				rest(DELAY_BOT);
			}
		}
		if (mouse_x > 224 && mouse_x < (224 + 66) && mouse_y > 206 && mouse_y < (206 + 37))
		{
			draw_sprite(buffer, mult, 224, 206);
			if (mouse_b == 1)
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				op = 3;
				aux = 2;
				rest(DELAY_BOT);
			}
		}
		if (mouse_x > 99 && mouse_x < (99 + 37) && mouse_y > 265 && mouse_y < (265 + 37))
		{
			draw_sprite(buffer, igual, 99, 265);
			if (mouse_b == 1)
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				if (aux != 1)
				{
					if (op == 1)
					{
						result = num1 + num2;
					}
					else if (op == 2)
					{
						result = num1 - num2;
					}
					else if (op == 3)
					{
						result = num1 * num2;
					}
					else if (op == 4)
					{
						result = num1 * 1.0 / num2;
					}
					aux = 3;
					play_sample(resposta, 255, 128, FREQ_GR, FALSE);
					rest(6000);
					if (result > 8000)
					{
						play_sample(mais_de, 255, 128, FREQ_GR, FALSE);
						rest(8000);
					}
				}
				rest(DELAY_BOT);
			}
		}
		if (mouse_x > 161 && mouse_x < (161 + 37) && mouse_y > 265 && mouse_y < (265 + 37))
		{
			draw_sprite(buffer, clear, 161, 265);
			if (mouse_b == 1)
			{
				play_sample(punch, 255, 128, FREQ_GR, FALSE);
				num1 = 0;
				num2 = 0;
				result = 0;
				op = 0;
				aux = 1;
				rest(DELAY_BOT);
			}
		}

		if (aux == 1)
		{
			textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d", num1);
		}
		else if (aux == 2)
		{
			if (op == 1)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d + %d", num1, num2);
			}
			else if (op == 2)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d - %d", num1, num2);
			}
			else if (op == 3)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d * %d", num1, num2);
			}
			else if (op == 4)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d / %d", num1, num2);
			}
		}
		else if (aux == 3)
		{
			if (op == 1)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d + %d = %.2f", num1, num2, result);
			}
			else if (op == 2)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d - %d = %.2f", num1, num2, result);
			}
			else if (op == 3)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d * %d = %.2f", num1, num2, result);
			}
			else if (op == 4)
			{
				textprintf_ex(buffer, font, 60, 40, makecol(0, 0, 0), -1, "%d / %d = %.2f", num1, num2, result);
			}
		}
		draw_sprite(buffer, boneco, 0, 0);
		draw_sprite(buffer, cursor, mouse_x, mouse_y);

		draw_sprite(screen, buffer, 0, 0);
		clear_to_color(buffer, makecol(255, 255, 255));
	}

	stop_midi();

	// FINALIZA��O
	destroy_bitmap(cursor);
	destroy_bitmap(buffer);
	destroy_bitmap(base);
	destroy_bitmap(boneco);
	destroy_bitmap(base_a);
	destroy_midi(musica);
	destroy_sample(punch);
	destroy_sample(resposta);
	destroy_sample(mais_de);
	// FINALIZA��O BOT�ES
	destroy_bitmap(um);
	destroy_bitmap(dois);
	destroy_bitmap(tres);
	destroy_bitmap(quatro);
	destroy_bitmap(cinco);
	destroy_bitmap(seis);
	destroy_bitmap(sete);
	destroy_bitmap(oito);
	destroy_bitmap(nove);
	destroy_bitmap(zero);
	destroy_bitmap(som);
	destroy_bitmap(sub);
	destroy_bitmap(mult);
	destroy_bitmap(div);
	destroy_bitmap(igual);
	destroy_bitmap(clear);

	return 0;
}
END_OF_MAIN();
