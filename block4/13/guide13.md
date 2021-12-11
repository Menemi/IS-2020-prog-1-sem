# Гайд по 13 лабе

## Советы
Нужно найти и скачать такой .mp3 файл, в метаданных которого нет текста, так будет значительно проще и эстетичнее выглядеть, потому что с текстом у вас перекроется пол консольки непонятными UTF-8 символами

## Гайд
Чтобы работать с нашей прогой, нам надо будет прописать в консоли следующее:

Путь до .exe файла:
```cd /D D:\ITMOre than a university\IS-2020-prog-1-sem\block4\13\cmake-build-debug```

Если кратко, то вот так:
```cd /диск ..\корневаяПапкаПроекта\cmake-build-debug```

В той папке у вас должно быть что-то такое
![/скриншот/](https://github.com/1Menemi1/IS-2020-prog-1-sem/blob/main/block4/13/cmake-build-debug/guide-images/13.png)

Вы вписываете в консоль такую команду (изменяя название .exe и .mp3 файлов на свои):
```13.exe --filepath=HDMI.mp3 --show```

И получаете свои метаданные файла:
```
TENC:  iTunes 12.0.1.26
TPE1:  BONES
TIT2: POVIS
TCOM:  Antonio
TDRC:  2014
TCON:  SESH
TRCK:  2/18
```

Дальше вы можете изменять всё, что захотите, вот мой пример команд и выводов:
```
13.exe --filepath=HDMI.mp3 --get=TIT2
TIT2: POVIS
```
```
13.exe --filepath=HDMI.mp3 --get=TDRC
TDRC:  2014
```
```
13.exe --filepath=HDMI.mp3 --set=TDRC --value=2015
```
```
13.exe --filepath=HDMI.mp3 --get=TDRC
TDRC: 2015
```
```
13.exe --filepath=HDMI.mp3 --show
TENC:  iTunes 12.0.1.26
TPE1:  BONES
TIT2: POVIS
TCOM:  Antonio
TDRC: 2015
TCON:  SESH
TRCK:  2/18
```

Как вы можете заметить, изменяется всё нормально, все данные сохраняются и при перезапуске программы мой изменённый будет равен именно 2015, а не 2014, так как раньше я его изменил
