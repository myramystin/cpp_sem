# Семинар 1

## Контакты

- телеграм https://t.me/on1kova
- чат https://t.me/+hxS-ajpFP7s4MzFi

## Лекции

- Канал с полезной инфой [t.me/hse_cxx_2026](t.me/hse_cxx_2026)

- [Сайтик с дедлайнами](https://base.cpp-hse.net/)

- По кнопке my Repo - ваш репозиторий. Там подробные гайды про то как сдавать задачи

- Код доступа - ami-cpp-2514-2


## Оценки

### 0.275 ДЗ + 0.1 Семинары + 0.625 Проект

Оценка за семинары = 0.5 * активность на парах + 0.5 * тесты

тестов ожидается 3 - 4 за модуль

## Настройка всего

- подробный гайд в setup.md в репозитории
- для пользователей windows - советую установить linux:
    - Virtual Box - https://www.virtualbox.org/ + Образ https://ubuntu.com/download/desktop (еще работает на маке с интелом)
    - Поставить рядом с виндой

### Всякое
- https://git-scm.com/cheat-sheet
- clang-format -i file.cpp
- сборка -- 
```bash
$ mkdir cd <repo-root>build # создать директорию, если еще не
$ cd <repo-root>build # перейти в директорию
$ make test_taskname
$ ./test_taskname
```
- сдача задачи
```bash
$ git checkout main && git git checkout -b submits/taskname
$ git add filename1 filename2 ...
$ git commit -m "message"
$ git push
```

и создать MR

