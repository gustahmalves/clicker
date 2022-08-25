#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

void menu()
{
  cout << "Aperte 'A' para Ativar o autoclick e aperte 'D' para Desativar\n";
}
void clicker()
{
  bool click = false; // seta uma variavel booleana de click para falso

  while (true)
  {
    if (GetAsyncKeyState('A'))
    { // GetAsyncKeyState determina se a tecla está UP ou DOWN, dependendo do estado com a letra ela vai atribuir outro valor a variável CLICK. LINK PARA LEITURA: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
      click = true;
    }
    else if (GetAsyncKeyState('D'))
    {
      click = false;
    }
    if (click == true)
    {
      mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0); // evento do mouse para realizar o click com o bot�o esquerdo
      mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);   // evento do mouse para realizar o click com o bot�o esquerdo. LINK PARA LEITURA: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-mouse_event && https://pyautogui.readthedocs.io/en/latest/mouse.html
      Sleep(1);                                    // Aqui voc� consegue setar o tempo de um click para o outro
    }
  }
}

int main()
{
  menu();
  clicker();
  return 0;
}
