#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <locale>

class TextEditor {
    private:
        std::wstring text;
        std::wstring clipboard;
        std::wstring selection;
        
    public:
        TextEditor() : text(L"Медведь, горящая машина, лес."), selection(L"горящая машина") {}
        
        std::wstring getText() const { return text; }
        void setText(const std::wstring& newText) { text = newText; }
        
        std::wstring getSelection() const { return selection; }
        void setSelection(const std::wstring& sel) { selection = sel; }
        
        std::wstring getClipboard() const { return clipboard; }
        void setClipboard(const std::wstring& clip) { clipboard = clip; }
        
        void copy() {
            if (!selection.empty()) {
                clipboard = selection;
                std::wcout << L"Скопировано: " << clipboard << std::endl;
            }
        }
        
        void paste() {
            if (!clipboard.empty()) {
                text += clipboard;
                std::wcout << L"Вставлено: " << clipboard << std::endl;
            }
        }
        
        void cut() {
            if (!selection.empty()) {
                clipboard = selection;
                size_t pos = text.find(selection);
                if (pos != std::wstring::npos) {
                    text.erase(pos, selection.length());
                }
                selection = L"";
                std::wcout << L"Вырезано: " << clipboard << std::endl;
            }
        }
        
        void show() const {
            std::wcout << L"Текст: " << text << std::endl;
            std::wcout << L"Выделение: " << selection << std::endl;
            std::wcout << L"Буфер обмена: " << clipboard << std::endl;
        }
};

// Интерфейс
class Command {
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
    };

    // Копировать
    class CopyCommand : public Command {
    private:
        TextEditor& editor;
        std::wstring savedSelection;
        
    public:
        CopyCommand(TextEditor& ed) : editor(ed) {}
        
        void execute() override {
            savedSelection = editor.getSelection();
            editor.copy();
        }
        
        void undo() override {
            std::wcout << L"Отмена Копирования" << std::endl;
            editor.setSelection(savedSelection);
        }
};

// Вставить
class PasteCommand : public Command {
    private:
        TextEditor& editor;
        std::wstring savedText;
        std::wstring savedClipboard;
        
    public:
        PasteCommand(TextEditor& ed) : editor(ed) {}
        
        void execute() override {
            savedText = editor.getText();
            savedClipboard = editor.getClipboard();
            editor.paste();
        }
        
        void undo() override {
            editor.setText(savedText);
            editor.setClipboard(savedClipboard);
            std::wcout << L"Отмена Вставки" << std::endl;
        }
};

// Вырезать
class CutCommand : public Command {
    private:
        TextEditor& editor;
        std::wstring savedText;
        std::wstring savedSelection;
        std::wstring savedClipboard;
        
    public:
        CutCommand(TextEditor& ed) : editor(ed) {}
        
        void execute() override {
            savedText = editor.getText();
            savedSelection = editor.getSelection();
            savedClipboard = editor.getClipboard();
            editor.cut();
        }
        
        void undo() override {
            editor.setText(savedText);
            editor.setSelection(savedSelection);
            editor.setClipboard(savedClipboard);
            std::wcout << L"Отмена Вырезания" << std::endl;
        }
};

// История
class CommandHistory {
    private:
        std::stack<Command*> history;
        
    public:
        ~CommandHistory() {
            while (!history.empty()) {
                delete history.top();
                history.pop();
            }
        }
        
        void push(Command* cmd) {
            history.push(cmd);
        }
        
        Command* pop() {
            if (history.empty()) return nullptr;
            Command* cmd = history.top();
            history.pop();
            return cmd;
        }
        
        bool isEmpty() const {
            return history.empty();
        }
};

// Клиентский код
class Application {
    private:
        TextEditor editor;
        CommandHistory history;
        
    public:
        void executeCommand(Command* cmd) {
            cmd->execute();
            history.push(cmd);
            std::wcout << L"Команда выполнена" << std::endl;
        }
        
        void undoLastCommand() {
            if (!history.isEmpty()) {
                Command* cmd = history.pop();
                cmd->undo();
                delete cmd;
                std::wcout << L"Отмена выполнена" << std::endl;
            } else {
                std::wcout << L"Нет команд для отмены" << std::endl;
            }
        }
        
        void showEditor() const {
            editor.show();
        }
        
        TextEditor& getEditor() { return editor; }
};

int main() {    
    setlocale(LC_ALL, "");
        
    Application app;
    
    std::wcout << L"Начальное состояние: " << std::endl;
    app.showEditor();
    
    // Команды
    std::wcout << L"\n1. Команда Копировать: " << std::endl;
    app.executeCommand(new CopyCommand(app.getEditor()));
    app.showEditor();
    
    std::wcout << L"\n2. Команда Вставить: " << std::endl;
    app.executeCommand(new PasteCommand(app.getEditor()));
    app.showEditor();
    
    std::wcout << L"\n3. Команда Вырезать: " << std::endl;
    app.executeCommand(new CutCommand(app.getEditor()));
    app.showEditor();
    
    // Отмена
    std::wcout << L"\n4. Отменяем последнюю команду (Вырезать): " << std::endl;
    app.undoLastCommand();
    app.showEditor();
    
    std::wcout << L"\n5. Отменяем следующую команду (Вставить): " << std::endl;
    app.undoLastCommand();
    app.showEditor();
    
    std::wcout << L"\n6. Пробуем отменить ещё раз: " << std::endl;
    app.undoLastCommand();
    
    return 0;
}