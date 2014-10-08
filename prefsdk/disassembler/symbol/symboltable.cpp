#include "symboltable.h"

namespace PrefSDK
{
    SymbolTable::SymbolTable(QObject *parent): QObject(parent)
    {
    }

    lua_Integer SymbolTable::count() const
    {
        return this->_symboltable.count();
    }

    bool SymbolTable::contains(const DataValue &address) const
    {
        return this->_symboltable.contains(address);
    }

    bool SymbolTable::isType(const DataValue &address, Symbol::Type symboltype) const
    {
        if(this->_symboltable.contains(address))
        {
            Symbol* symbol = this->_symboltable[address];
            return symbol->type() == symboltype;
        }

        return false;
    }

    void SymbolTable::set(Symbol::Type symboltype, const DataValue &address, const QString &name)
    {
        this->set(symboltype, address, address.dataType(), name);
    }

    void SymbolTable::set(Symbol::Type symboltype, const DataValue &address, DataType::Type datatype, const QString &name)
    {
        if(this->_symboltable.contains(address))
        {
            Symbol* symbol = this->_symboltable[address];
            symbol->setType(symboltype);
            symbol->setDataType(datatype);
            symbol->setName(name);
            return;
        }

        this->_symboltable[address] = new Symbol(symboltype, address, datatype, name, this);
    }

    QString SymbolTable::name(const DataValue &address) const
    {
        if(!this->_symboltable.contains(address))
            return QString();

        return this->_symboltable[address]->name();
    }

    Symbol *SymbolTable::get(const DataValue &address) const
    {
        return this->_symboltable[address];
    }
}
