
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  ExprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, TYPEINT = 13, 
    TYPECHAR = 14, INT = 15, VAR = 16, WS = 17
  };

  enum {
    RuleProg = 0, RuleBase = 1, RuleCore = 2, RuleCode = 3, RuleRet = 4, 
    RuleVari = 5, RuleExpr = 6, RuleTypevar = 7
  };

  ExprParser(antlr4::TokenStream *input);
  ~ExprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class BaseContext;
  class CoreContext;
  class CodeContext;
  class RetContext;
  class VariContext;
  class ExprContext;
  class TypevarContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BaseContext *base();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  BaseContext : public antlr4::ParserRuleContext {
  public:
    BaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CoreContext *core();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseContext* base();

  class  CoreContext : public antlr4::ParserRuleContext {
  public:
    CoreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RetContext *ret();
    std::vector<CodeContext *> code();
    CodeContext* code(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CoreContext* core();

  class  CodeContext : public antlr4::ParserRuleContext {
  public:
    CodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypevarContext *typevar();
    VariContext *vari();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeContext* code();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RetContext* ret();

  class  VariContext : public antlr4::ParserRuleContext {
  public:
    VariContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VariContext() = default;
    void copyFrom(VariContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AffContext : public VariContext {
  public:
    AffContext(VariContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DecContext : public VariContext {
  public:
    DecContext(VariContext *ctx);

    antlr4::tree::TerminalNode *VAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpressionContext : public VariContext {
  public:
    ExpressionContext(VariContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VariContext* vari();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParContext : public ExprContext {
  public:
    ParContext(ExprContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DivContext : public ExprContext {
  public:
    DivContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddContext : public ExprContext {
  public:
    AddContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubContext : public ExprContext {
  public:
    SubContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MultContext : public ExprContext {
  public:
    MultContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarContext : public ExprContext {
  public:
    VarContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *VAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LdconstContext : public ExprContext {
  public:
    LdconstContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  TypevarContext : public antlr4::ParserRuleContext {
  public:
    TypevarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypevarContext() = default;
    void copyFrom(TypevarContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CharContext : public TypevarContext {
  public:
    CharContext(TypevarContext *ctx);

    antlr4::tree::TerminalNode *TYPECHAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntContext : public TypevarContext {
  public:
    IntContext(TypevarContext *ctx);

    antlr4::tree::TerminalNode *TYPEINT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypevarContext* typevar();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

