# 🚀 Nelder-Mead Optimizer (Windows)

**Проект по реализации метода Нелдера-Мида с графическим интерфейсом и тестированием**

[![Qt](https://img.shields.io/badge/Qt-6.6.1-green?logo=qt)](https://www.qt.io/)
[![Windows](https://img.shields.io/badge/Windows-10%2F11-blue?logo=windows)](https://www.microsoft.com/)
[![Tests](https://img.shields.io/badge/Тесты-Passed-brightgreen)](https://github.com/google/googletest)

<img src="jeje.png" width="600" alt="Скриншот интерфейса">

---

## 🛠 Установка и запуск (для Windows)

### Требования:
- Windows 10/11 (64-bit)
- [Visual Studio 2022](https://visualstudio.microsoft.com/ru/) (Community Edition)
- [Qt 6.6.1](https://www.qt.io/download) 
### Шаг 1: Подготовка проекта
1. Скачайте исправленную версию проекта с GitHub:
   ```url
   https://github.com/yourusername/nelder-mead-optimizer/archive/refs/heads/cmake-fix.zip
Распакуйте архив в короткий путь без пробелов и кириллицы:
 ```url
C:\Projects\NelderMead\
```
### Шаг 2:**Соберите проект**:
   - Откройте файл `NelderMeadOptimizer.sln` из папки `build` в Visual Studio.
   - В меню выберите: `Сборка → Собрать решение`.
### Шаг 3: **Qt**
   - Откройте Qt-creator
   - Выберете скачанный проект("CmakeLists.txt")
   - Build -> Run (Ctrl + R)
     
## 🧪 Тестирование (для разработчиков)

1. **Запуск тестов**:
   - В Visual Studio откройте **Test Explorer** (Тест → Обозреватель тестов).
   - Нажмите **Запустить все**.
## 👥 Команда

| Участник             | Роль                | Вклад                              |
|----------------------|---------------------|------------------------------------|
| **Плотников Кирилл** | Back-end разработчик | Алгоритм, интеграция DLL, CMake   |
| **Ярахтина Алена**   | Front-end инженер   | Qt-интерфейс, визуализация        |
| **Колобков Никита**  | QA инженер          | Юнит-тесты, документация          |

---

Проект создан с ❤️ для курса "Методы оптимизации".  
