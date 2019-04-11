
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  ExprParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, TYPEINT = 20, 
    TYPECHAR = 21, INT = 22, VAR = 23, WS = 24
  };

  enum {
    RuleProg = 0, RuleBase = 1, RuleCore = 2, RuleCode = 3, RuleCondition = 4, 
    RuleCondIf = 5, RuleCondElse = 6, RuleIfCore = 7, RuleBoolExpressionWhile = 8, 
    RuleBoolExpression = 9, RulePredicat = 10, RuleRet = 11, RuleVari = 12, 
    RuleExpr = 13, RuleTerme = 14, RuleFacteur = 15, RuleTypevar = 16
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
  class ConditionContext;
  class CondIfContext;
  class CondElseContext;
  class IfCoreContext;
  class BoolExpressionWhileContext;
  class BoolExpressionContext;
  class PredicatContext;
  class RetContext;
  class VariContext;
  class ExprContext;
  class TermeContext;
  class FacteurContext;
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
   
    CodeContext() = default;
    void copyFrom(CodeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AffContext : public CodeContext {
  public:
    AffContext(CodeContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CondifContext : public CodeContext {
  public:
    CondifContext(CodeContext *ctx);

    ConditionContext *condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DecdefContext : public CodeContext {
  public:
    DecdefContext(CodeContext *ctx);

    TypevarContext *typevar();
    VariContext *vari();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CodeContext* code();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConditionContext() = default;
    void copyFrom(ConditionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileLoopContext : public ConditionContext {
  public:
    WhileLoopContext(ConditionContext *ctx);

    BoolExpressionWhileContext *boolExpressionWhile();
    CondIfContext *condIf();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfElseContext : public ConditionContext {
  public:
    IfElseContext(ConditionContext *ctx);

    BoolExpressionContext *boolExpression();
    CondIfContext *condIf();
    CondElseContext *condElse();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleIfContext : public ConditionContext {
  public:
    SimpleIfContext(ConditionContext *ctx);

    BoolExpressionContext *boolExpression();
    CondIfContext *condIf();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConditionContext* condition();

  class  CondIfContext : public antlr4::ParserRuleContext {
  public:
    CondIfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfCoreContext *ifCore();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondIfContext* condIf();

  class  CondElseContext : public antlr4::ParserRuleContext {
  public:
    CondElseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfCoreContext *ifCore();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondElseContext* condElse();

  class  IfCoreContext : public antlr4::ParserRuleContext {
  public:
    IfCoreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IfCoreContext() = default;
    void copyFrom(IfCoreContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfCommandeContext : public IfCoreContext {
  public:
    IfCommandeContext(IfCoreContext *ctx);

    std::vector<CodeContext *> code();
    CodeContext* code(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfRetContext : public IfCoreContext {
  public:
    IfRetContext(IfCoreContext *ctx);

    RetContext *ret();
    std::vector<CodeContext *> code();
    CodeContext* code(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IfCoreContext* ifCore();

  class  BoolExpressionWhileContext : public antlr4::ParserRuleContext {
  public:
    BoolExpressionWhileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PredicatContext *predicat();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolExpressionWhileContext* boolExpressionWhile();

  class  BoolExpressionContext : public antlr4::ParserRuleContext {
  public:
    BoolExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PredicatContext *predicat();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BoolExpressionContext* boolExpression();

  class  PredicatContext : public antlr4::ParserRuleContext {
  public:
    PredicatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PredicatContext() = default;
    void copyFrom(PredicatContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  EgalContext : public PredicatContext {
  public:
    EgalContext(PredicatContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LtContext : public PredicatContext {
  public:
    LtContext(PredicatContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LeContext : public PredicatContext {
  public:
    LeContext(PredicatContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GtContext : public PredicatContext {
  public:
    GtContext(PredicatContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GeContext : public PredicatContext {
  public:
    GeContext(PredicatContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PredicatContext* predicat();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


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

  class  DefVarContext : public VariContext {
  public:
    DefVarContext(VariContext *ctx);

    antlr4::tree::TerminalNode *VAR();
    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DecVarContext : public VariContext {
  public:
    DecVarContext(VariContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> VAR();
    antlr4::tree::TerminalNode* VAR(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VariContext* vari();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermeContext *> terme();
    TermeContext* terme(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  TermeContext : public antlr4::ParserRuleContext {
  public:
    TermeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FacteurContext *> facteur();
    FacteurContext* facteur(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermeContext* terme();

  class  FacteurContext : public antlr4::ParserRuleContext {
  public:
    FacteurContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FacteurContext() = default;
    void copyFrom(FacteurContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FactVarContext : public FacteurContext {
  public:
    FactVarContext(FacteurContext *ctx);

    antlr4::tree::TerminalNode *VAR();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactIntContext : public FacteurContext {
  public:
    FactIntContext(FacteurContext *ctx);

    antlr4::tree::TerminalNode *INT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FactParContext : public FacteurContext {
  public:
    FactParContext(FacteurContext *ctx);

    ExprContext *expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FacteurContext* facteur();

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

