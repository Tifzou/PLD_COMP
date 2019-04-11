
// Generated from Expr.g4 by ANTLR 4.7.2


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::BaseContext* ExprParser::ProgContext::base() {
  return getRuleContext<ExprParser::BaseContext>(0);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}


antlrcpp::Any ExprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    base();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseContext ------------------------------------------------------------------

ExprParser::BaseContext::BaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::CoreContext* ExprParser::BaseContext::core() {
  return getRuleContext<ExprParser::CoreContext>(0);
}


size_t ExprParser::BaseContext::getRuleIndex() const {
  return ExprParser::RuleBase;
}


antlrcpp::Any ExprParser::BaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBase(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BaseContext* ExprParser::base() {
  BaseContext *_localctx = _tracker.createInstance<BaseContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleBase);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(36);
    match(ExprParser::T__0);
    setState(37);
    match(ExprParser::T__1);
    setState(38);
    match(ExprParser::T__2);
    setState(39);
    core();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CoreContext ------------------------------------------------------------------

ExprParser::CoreContext::CoreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::RetContext* ExprParser::CoreContext::ret() {
  return getRuleContext<ExprParser::RetContext>(0);
}

std::vector<ExprParser::CodeContext *> ExprParser::CoreContext::code() {
  return getRuleContexts<ExprParser::CodeContext>();
}

ExprParser::CodeContext* ExprParser::CoreContext::code(size_t i) {
  return getRuleContext<ExprParser::CodeContext>(i);
}


size_t ExprParser::CoreContext::getRuleIndex() const {
  return ExprParser::RuleCore;
}


antlrcpp::Any ExprParser::CoreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCore(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::CoreContext* ExprParser::core() {
  CoreContext *_localctx = _tracker.createInstance<CoreContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleCore);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(ExprParser::T__3);
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::T__7)
      | (1ULL << ExprParser::T__9)
      | (1ULL << ExprParser::TYPEINT)
      | (1ULL << ExprParser::TYPECHAR)
      | (1ULL << ExprParser::VAR))) != 0)) {
      setState(42);
      code();
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(48);
    ret();
    setState(49);
    match(ExprParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CodeContext ------------------------------------------------------------------

ExprParser::CodeContext::CodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::CodeContext::getRuleIndex() const {
  return ExprParser::RuleCode;
}

void ExprParser::CodeContext::copyFrom(CodeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AffContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::AffContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::ExprContext* ExprParser::AffContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::AffContext::AffContext(CodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::AffContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAff(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondifContext ------------------------------------------------------------------

ExprParser::ConditionContext* ExprParser::CondifContext::condition() {
  return getRuleContext<ExprParser::ConditionContext>(0);
}

ExprParser::CondifContext::CondifContext(CodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::CondifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCondif(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecdefContext ------------------------------------------------------------------

ExprParser::TypevarContext* ExprParser::DecdefContext::typevar() {
  return getRuleContext<ExprParser::TypevarContext>(0);
}

ExprParser::VariContext* ExprParser::DecdefContext::vari() {
  return getRuleContext<ExprParser::VariContext>(0);
}

ExprParser::DecdefContext::DecdefContext(CodeContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DecdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDecdef(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::CodeContext* ExprParser::code() {
  CodeContext *_localctx = _tracker.createInstance<CodeContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleCode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(61);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::TYPEINT:
      case ExprParser::TYPECHAR: {
        _localctx = dynamic_cast<CodeContext *>(_tracker.createInstance<ExprParser::DecdefContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(51);
        typevar();
        setState(52);
        vari();
        setState(53);
        match(ExprParser::T__5);
        break;
      }

      case ExprParser::VAR: {
        _localctx = dynamic_cast<CodeContext *>(_tracker.createInstance<ExprParser::AffContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(55);
        match(ExprParser::VAR);
        setState(56);
        match(ExprParser::T__6);
        setState(57);
        expr();
        setState(58);
        match(ExprParser::T__5);
        break;
      }

      case ExprParser::T__7:
      case ExprParser::T__9: {
        _localctx = dynamic_cast<CodeContext *>(_tracker.createInstance<ExprParser::CondifContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(60);
        condition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

ExprParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ConditionContext::getRuleIndex() const {
  return ExprParser::RuleCondition;
}

void ExprParser::ConditionContext::copyFrom(ConditionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileLoopContext ------------------------------------------------------------------

ExprParser::BoolExpressionWhileContext* ExprParser::WhileLoopContext::boolExpressionWhile() {
  return getRuleContext<ExprParser::BoolExpressionWhileContext>(0);
}

ExprParser::CondIfContext* ExprParser::WhileLoopContext::condIf() {
  return getRuleContext<ExprParser::CondIfContext>(0);
}

ExprParser::WhileLoopContext::WhileLoopContext(ConditionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfElseContext ------------------------------------------------------------------

ExprParser::BoolExpressionContext* ExprParser::IfElseContext::boolExpression() {
  return getRuleContext<ExprParser::BoolExpressionContext>(0);
}

ExprParser::CondIfContext* ExprParser::IfElseContext::condIf() {
  return getRuleContext<ExprParser::CondIfContext>(0);
}

ExprParser::CondElseContext* ExprParser::IfElseContext::condElse() {
  return getRuleContext<ExprParser::CondElseContext>(0);
}

ExprParser::IfElseContext::IfElseContext(ConditionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::IfElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIfElse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleIfContext ------------------------------------------------------------------

ExprParser::BoolExpressionContext* ExprParser::SimpleIfContext::boolExpression() {
  return getRuleContext<ExprParser::BoolExpressionContext>(0);
}

ExprParser::CondIfContext* ExprParser::SimpleIfContext::condIf() {
  return getRuleContext<ExprParser::CondIfContext>(0);
}

ExprParser::SimpleIfContext::SimpleIfContext(ConditionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::SimpleIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSimpleIf(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::ConditionContext* ExprParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ConditionContext *>(_tracker.createInstance<ExprParser::IfElseContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(63);
      match(ExprParser::T__7);
      setState(64);
      match(ExprParser::T__1);
      setState(65);
      boolExpression();
      setState(66);
      match(ExprParser::T__2);
      setState(67);
      match(ExprParser::T__3);
      setState(68);
      condIf();
      setState(69);
      match(ExprParser::T__4);
      setState(70);
      match(ExprParser::T__8);
      setState(71);
      match(ExprParser::T__3);
      setState(72);
      condElse();
      setState(73);
      match(ExprParser::T__4);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ConditionContext *>(_tracker.createInstance<ExprParser::SimpleIfContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(75);
      match(ExprParser::T__7);
      setState(76);
      match(ExprParser::T__1);
      setState(77);
      boolExpression();
      setState(78);
      match(ExprParser::T__2);
      setState(79);
      match(ExprParser::T__3);
      setState(80);
      condIf();
      setState(81);
      match(ExprParser::T__4);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<ConditionContext *>(_tracker.createInstance<ExprParser::WhileLoopContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(83);
      match(ExprParser::T__9);
      setState(84);
      match(ExprParser::T__1);
      setState(85);
      boolExpressionWhile();
      setState(86);
      match(ExprParser::T__2);
      setState(87);
      match(ExprParser::T__3);
      setState(88);
      condIf();
      setState(89);
      match(ExprParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondIfContext ------------------------------------------------------------------

ExprParser::CondIfContext::CondIfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IfCoreContext* ExprParser::CondIfContext::ifCore() {
  return getRuleContext<ExprParser::IfCoreContext>(0);
}


size_t ExprParser::CondIfContext::getRuleIndex() const {
  return ExprParser::RuleCondIf;
}


antlrcpp::Any ExprParser::CondIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCondIf(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::CondIfContext* ExprParser::condIf() {
  CondIfContext *_localctx = _tracker.createInstance<CondIfContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleCondIf);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    ifCore();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondElseContext ------------------------------------------------------------------

ExprParser::CondElseContext::CondElseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::IfCoreContext* ExprParser::CondElseContext::ifCore() {
  return getRuleContext<ExprParser::IfCoreContext>(0);
}


size_t ExprParser::CondElseContext::getRuleIndex() const {
  return ExprParser::RuleCondElse;
}


antlrcpp::Any ExprParser::CondElseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCondElse(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::CondElseContext* ExprParser::condElse() {
  CondElseContext *_localctx = _tracker.createInstance<CondElseContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleCondElse);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    ifCore();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfCoreContext ------------------------------------------------------------------

ExprParser::IfCoreContext::IfCoreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::IfCoreContext::getRuleIndex() const {
  return ExprParser::RuleIfCore;
}

void ExprParser::IfCoreContext::copyFrom(IfCoreContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfCommandeContext ------------------------------------------------------------------

std::vector<ExprParser::CodeContext *> ExprParser::IfCommandeContext::code() {
  return getRuleContexts<ExprParser::CodeContext>();
}

ExprParser::CodeContext* ExprParser::IfCommandeContext::code(size_t i) {
  return getRuleContext<ExprParser::CodeContext>(i);
}

ExprParser::IfCommandeContext::IfCommandeContext(IfCoreContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::IfCommandeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIfCommande(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfRetContext ------------------------------------------------------------------

ExprParser::RetContext* ExprParser::IfRetContext::ret() {
  return getRuleContext<ExprParser::RetContext>(0);
}

std::vector<ExprParser::CodeContext *> ExprParser::IfRetContext::code() {
  return getRuleContexts<ExprParser::CodeContext>();
}

ExprParser::CodeContext* ExprParser::IfRetContext::code(size_t i) {
  return getRuleContext<ExprParser::CodeContext>(i);
}

ExprParser::IfRetContext::IfRetContext(IfCoreContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::IfRetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIfRet(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::IfCoreContext* ExprParser::ifCore() {
  IfCoreContext *_localctx = _tracker.createInstance<IfCoreContext>(_ctx, getState());
  enterRule(_localctx, 14, ExprParser::RuleIfCore);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(110);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IfCoreContext *>(_tracker.createInstance<ExprParser::IfCommandeContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExprParser::T__7)
        | (1ULL << ExprParser::T__9)
        | (1ULL << ExprParser::TYPEINT)
        | (1ULL << ExprParser::TYPECHAR)
        | (1ULL << ExprParser::VAR))) != 0)) {
        setState(97);
        code();
        setState(102);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IfCoreContext *>(_tracker.createInstance<ExprParser::IfRetContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExprParser::T__7)
        | (1ULL << ExprParser::T__9)
        | (1ULL << ExprParser::TYPEINT)
        | (1ULL << ExprParser::TYPECHAR)
        | (1ULL << ExprParser::VAR))) != 0)) {
        setState(103);
        code();
        setState(108);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(109);
      ret();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolExpressionWhileContext ------------------------------------------------------------------

ExprParser::BoolExpressionWhileContext::BoolExpressionWhileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::PredicatContext* ExprParser::BoolExpressionWhileContext::predicat() {
  return getRuleContext<ExprParser::PredicatContext>(0);
}


size_t ExprParser::BoolExpressionWhileContext::getRuleIndex() const {
  return ExprParser::RuleBoolExpressionWhile;
}


antlrcpp::Any ExprParser::BoolExpressionWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBoolExpressionWhile(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BoolExpressionWhileContext* ExprParser::boolExpressionWhile() {
  BoolExpressionWhileContext *_localctx = _tracker.createInstance<BoolExpressionWhileContext>(_ctx, getState());
  enterRule(_localctx, 16, ExprParser::RuleBoolExpressionWhile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(112);
    predicat();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolExpressionContext ------------------------------------------------------------------

ExprParser::BoolExpressionContext::BoolExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::PredicatContext* ExprParser::BoolExpressionContext::predicat() {
  return getRuleContext<ExprParser::PredicatContext>(0);
}


size_t ExprParser::BoolExpressionContext::getRuleIndex() const {
  return ExprParser::RuleBoolExpression;
}


antlrcpp::Any ExprParser::BoolExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitBoolExpression(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::BoolExpressionContext* ExprParser::boolExpression() {
  BoolExpressionContext *_localctx = _tracker.createInstance<BoolExpressionContext>(_ctx, getState());
  enterRule(_localctx, 18, ExprParser::RuleBoolExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    predicat();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredicatContext ------------------------------------------------------------------

ExprParser::PredicatContext::PredicatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::PredicatContext::getRuleIndex() const {
  return ExprParser::RulePredicat;
}

void ExprParser::PredicatContext::copyFrom(PredicatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- EgalContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::EgalContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::EgalContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::EgalContext::EgalContext(PredicatContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::EgalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitEgal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LtContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::LtContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::LtContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::LtContext::LtContext(PredicatContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::LeContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::LeContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::LeContext::LeContext(PredicatContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLe(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GtContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::GtContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::GtContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::GtContext::GtContext(PredicatContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::GtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitGt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GeContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::GeContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::GeContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::GeContext::GeContext(PredicatContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::GeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitGe(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::PredicatContext* ExprParser::predicat() {
  PredicatContext *_localctx = _tracker.createInstance<PredicatContext>(_ctx, getState());
  enterRule(_localctx, 20, ExprParser::RulePredicat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PredicatContext *>(_tracker.createInstance<ExprParser::EgalContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(116);
      expr();
      setState(117);
      match(ExprParser::T__10);
      setState(118);
      expr();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PredicatContext *>(_tracker.createInstance<ExprParser::GeContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(120);
      expr();
      setState(121);
      match(ExprParser::T__11);
      setState(122);
      expr();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<PredicatContext *>(_tracker.createInstance<ExprParser::GtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(124);
      expr();
      setState(125);
      match(ExprParser::T__12);
      setState(126);
      expr();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<PredicatContext *>(_tracker.createInstance<ExprParser::LeContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(128);
      expr();
      setState(129);
      match(ExprParser::T__13);
      setState(130);
      expr();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<PredicatContext *>(_tracker.createInstance<ExprParser::LtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(132);
      expr();
      setState(133);
      match(ExprParser::T__14);
      setState(134);
      expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

ExprParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExprContext* ExprParser::RetContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}


size_t ExprParser::RetContext::getRuleIndex() const {
  return ExprParser::RuleRet;
}


antlrcpp::Any ExprParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RetContext* ExprParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 22, ExprParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    match(ExprParser::T__15);
    setState(139);
    expr();
    setState(140);
    match(ExprParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariContext ------------------------------------------------------------------

ExprParser::VariContext::VariContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::VariContext::getRuleIndex() const {
  return ExprParser::RuleVari;
}

void ExprParser::VariContext::copyFrom(VariContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DefVarContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::DefVarContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::ExprContext* ExprParser::DefVarContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::DefVarContext::DefVarContext(VariContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DefVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDefVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecVarContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> ExprParser::DecVarContext::VAR() {
  return getTokens(ExprParser::VAR);
}

tree::TerminalNode* ExprParser::DecVarContext::VAR(size_t i) {
  return getToken(ExprParser::VAR, i);
}

ExprParser::DecVarContext::DecVarContext(VariContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DecVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDecVar(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VariContext* ExprParser::vari() {
  VariContext *_localctx = _tracker.createInstance<VariContext>(_ctx, getState());
  enterRule(_localctx, 24, ExprParser::RuleVari);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariContext *>(_tracker.createInstance<ExprParser::DecVarContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(142);
      match(ExprParser::VAR);
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == ExprParser::T__16) {
        setState(143);
        match(ExprParser::T__16);
        setState(144);
        match(ExprParser::VAR);
        setState(149);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariContext *>(_tracker.createInstance<ExprParser::DefVarContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(150);
      match(ExprParser::VAR);
      setState(151);
      match(ExprParser::T__6);
      setState(152);
      expr();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::TermeContext *> ExprParser::ExprContext::terme() {
  return getRuleContexts<ExprParser::TermeContext>();
}

ExprParser::TermeContext* ExprParser::ExprContext::terme(size_t i) {
  return getRuleContext<ExprParser::TermeContext>(i);
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}


antlrcpp::Any ExprParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprContext* ExprParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 26, ExprParser::RuleExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    terme();
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__17) {
      setState(156);
      match(ExprParser::T__17);
      setState(157);
      terme();
      setState(162);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermeContext ------------------------------------------------------------------

ExprParser::TermeContext::TermeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::FacteurContext *> ExprParser::TermeContext::facteur() {
  return getRuleContexts<ExprParser::FacteurContext>();
}

ExprParser::FacteurContext* ExprParser::TermeContext::facteur(size_t i) {
  return getRuleContext<ExprParser::FacteurContext>(i);
}


size_t ExprParser::TermeContext::getRuleIndex() const {
  return ExprParser::RuleTerme;
}


antlrcpp::Any ExprParser::TermeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTerme(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TermeContext* ExprParser::terme() {
  TermeContext *_localctx = _tracker.createInstance<TermeContext>(_ctx, getState());
  enterRule(_localctx, 28, ExprParser::RuleTerme);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    facteur();
    setState(168);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::T__18) {
      setState(164);
      match(ExprParser::T__18);
      setState(165);
      facteur();
      setState(170);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FacteurContext ------------------------------------------------------------------

ExprParser::FacteurContext::FacteurContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::FacteurContext::getRuleIndex() const {
  return ExprParser::RuleFacteur;
}

void ExprParser::FacteurContext::copyFrom(FacteurContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FactVarContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FactVarContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::FactVarContext::FactVarContext(FacteurContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FactVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFactVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactIntContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::FactIntContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::FactIntContext::FactIntContext(FacteurContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FactIntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFactInt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FactParContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::FactParContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::FactParContext::FactParContext(FacteurContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::FactParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFactPar(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::FacteurContext* ExprParser::facteur() {
  FacteurContext *_localctx = _tracker.createInstance<FacteurContext>(_ctx, getState());
  enterRule(_localctx, 30, ExprParser::RuleFacteur);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INT: {
        _localctx = dynamic_cast<FacteurContext *>(_tracker.createInstance<ExprParser::FactIntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(171);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::VAR: {
        _localctx = dynamic_cast<FacteurContext *>(_tracker.createInstance<ExprParser::FactVarContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(172);
        match(ExprParser::VAR);
        break;
      }

      case ExprParser::T__1: {
        _localctx = dynamic_cast<FacteurContext *>(_tracker.createInstance<ExprParser::FactParContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(173);
        match(ExprParser::T__1);
        setState(174);
        expr();
        setState(175);
        match(ExprParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypevarContext ------------------------------------------------------------------

ExprParser::TypevarContext::TypevarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::TypevarContext::getRuleIndex() const {
  return ExprParser::RuleTypevar;
}

void ExprParser::TypevarContext::copyFrom(TypevarContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::CharContext::TYPECHAR() {
  return getToken(ExprParser::TYPECHAR, 0);
}

ExprParser::CharContext::CharContext(TypevarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::IntContext::TYPEINT() {
  return getToken(ExprParser::TYPEINT, 0);
}

ExprParser::IntContext::IntContext(TypevarContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::TypevarContext* ExprParser::typevar() {
  TypevarContext *_localctx = _tracker.createInstance<TypevarContext>(_ctx, getState());
  enterRule(_localctx, 32, ExprParser::RuleTypevar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(181);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::TYPEINT: {
        _localctx = dynamic_cast<TypevarContext *>(_tracker.createInstance<ExprParser::IntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(179);
        match(ExprParser::TYPEINT);
        break;
      }

      case ExprParser::TYPECHAR: {
        _localctx = dynamic_cast<TypevarContext *>(_tracker.createInstance<ExprParser::CharContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(180);
        match(ExprParser::TYPECHAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "base", "core", "code", "condition", "condIf", "condElse", "ifCore", 
  "boolExpressionWhile", "boolExpression", "predicat", "ret", "vari", "expr", 
  "terme", "facteur", "typevar"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'int main'", "'('", "')'", "'{'", "'}'", "';'", "'='", "'if'", "'else'", 
  "'while'", "'=='", "'>='", "'>'", "'<='", "'<'", "'return'", "','", "'+'", 
  "'*'", "'int'", "'char'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "TYPEINT", "TYPECHAR", "INT", "VAR", "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1a, 0xba, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x2e, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x31, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x40, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x5e, 0xa, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x7, 0x9, 0x65, 0xa, 0x9, 0xc, 
    0x9, 0xe, 0x9, 0x68, 0xb, 0x9, 0x3, 0x9, 0x7, 0x9, 0x6b, 0xa, 0x9, 0xc, 
    0x9, 0xe, 0x9, 0x6e, 0xb, 0x9, 0x3, 0x9, 0x5, 0x9, 0x71, 0xa, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x8b, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x94, 0xa, 
    0xe, 0xc, 0xe, 0xe, 0xe, 0x97, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x5, 0xe, 0x9c, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xa1, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xa4, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x7, 0x10, 0xa9, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xac, 0xb, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x5, 0x11, 0xb4, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xb8, 0xa, 
    0x12, 0x3, 0x12, 0x2, 0x2, 0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x2, 0x2, 
    0x2, 0xbb, 0x2, 0x24, 0x3, 0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3f, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x70, 0x3, 0x2, 0x2, 0x2, 0x12, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x74, 0x3, 0x2, 0x2, 0x2, 0x16, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xa5, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x22, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x25, 0x5, 0x4, 0x3, 0x2, 0x25, 0x3, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 
    0x7, 0x3, 0x2, 0x2, 0x27, 0x28, 0x7, 0x4, 0x2, 0x2, 0x28, 0x29, 0x7, 
    0x5, 0x2, 0x2, 0x29, 0x2a, 0x5, 0x6, 0x4, 0x2, 0x2a, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x2f, 0x7, 0x6, 0x2, 0x2, 0x2c, 0x2e, 0x5, 0x8, 0x5, 
    0x2, 0x2d, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x32, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 
    0x5, 0x18, 0xd, 0x2, 0x33, 0x34, 0x7, 0x7, 0x2, 0x2, 0x34, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x36, 0x5, 0x22, 0x12, 0x2, 0x36, 0x37, 0x5, 0x1a, 
    0xe, 0x2, 0x37, 0x38, 0x7, 0x8, 0x2, 0x2, 0x38, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x39, 0x3a, 0x7, 0x19, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x9, 0x2, 0x2, 
    0x3b, 0x3c, 0x5, 0x1c, 0xf, 0x2, 0x3c, 0x3d, 0x7, 0x8, 0x2, 0x2, 0x3d, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x5, 0xa, 0x6, 0x2, 0x3f, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x3f, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x9, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0xa, 
    0x2, 0x2, 0x42, 0x43, 0x7, 0x4, 0x2, 0x2, 0x43, 0x44, 0x5, 0x14, 0xb, 
    0x2, 0x44, 0x45, 0x7, 0x5, 0x2, 0x2, 0x45, 0x46, 0x7, 0x6, 0x2, 0x2, 
    0x46, 0x47, 0x5, 0xc, 0x7, 0x2, 0x47, 0x48, 0x7, 0x7, 0x2, 0x2, 0x48, 
    0x49, 0x7, 0xb, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x6, 0x2, 0x2, 0x4a, 0x4b, 
    0x5, 0xe, 0x8, 0x2, 0x4b, 0x4c, 0x7, 0x7, 0x2, 0x2, 0x4c, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0xa, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x4, 
    0x2, 0x2, 0x4f, 0x50, 0x5, 0x14, 0xb, 0x2, 0x50, 0x51, 0x7, 0x5, 0x2, 
    0x2, 0x51, 0x52, 0x7, 0x6, 0x2, 0x2, 0x52, 0x53, 0x5, 0xc, 0x7, 0x2, 
    0x53, 0x54, 0x7, 0x7, 0x2, 0x2, 0x54, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x55, 
    0x56, 0x7, 0xc, 0x2, 0x2, 0x56, 0x57, 0x7, 0x4, 0x2, 0x2, 0x57, 0x58, 
    0x5, 0x12, 0xa, 0x2, 0x58, 0x59, 0x7, 0x5, 0x2, 0x2, 0x59, 0x5a, 0x7, 
    0x6, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0xc, 0x7, 0x2, 0x5b, 0x5c, 0x7, 0x7, 
    0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0xb, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x5, 0x10, 0x9, 0x2, 0x60, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x5, 0x10, 0x9, 0x2, 0x62, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 0x5, 0x8, 0x5, 0x2, 0x64, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x8, 0x5, 0x2, 
    0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x5, 
    0x18, 0xd, 0x2, 0x70, 0x66, 0x3, 0x2, 0x2, 0x2, 0x70, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x11, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x5, 0x16, 0xc, 
    0x2, 0x73, 0x13, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x5, 0x16, 0xc, 0x2, 
    0x75, 0x15, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x5, 0x1c, 0xf, 0x2, 0x77, 
    0x78, 0x7, 0xd, 0x2, 0x2, 0x78, 0x79, 0x5, 0x1c, 0xf, 0x2, 0x79, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0x1c, 0xf, 0x2, 0x7b, 0x7c, 0x7, 
    0xe, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x1c, 0xf, 0x2, 0x7d, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x7f, 0x5, 0x1c, 0xf, 0x2, 0x7f, 0x80, 0x7, 0xf, 0x2, 
    0x2, 0x80, 0x81, 0x5, 0x1c, 0xf, 0x2, 0x81, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x5, 0x1c, 0xf, 0x2, 0x83, 0x84, 0x7, 0x10, 0x2, 0x2, 0x84, 
    0x85, 0x5, 0x1c, 0xf, 0x2, 0x85, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 
    0x5, 0x1c, 0xf, 0x2, 0x87, 0x88, 0x7, 0x11, 0x2, 0x2, 0x88, 0x89, 0x5, 
    0x1c, 0xf, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x82, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x12, 0x2, 0x2, 0x8d, 
    0x8e, 0x5, 0x1c, 0xf, 0x2, 0x8e, 0x8f, 0x7, 0x8, 0x2, 0x2, 0x8f, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x90, 0x95, 0x7, 0x19, 0x2, 0x2, 0x91, 0x92, 0x7, 
    0x13, 0x2, 0x2, 0x92, 0x94, 0x7, 0x19, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x7, 0x19, 0x2, 0x2, 0x99, 
    0x9a, 0x7, 0x9, 0x2, 0x2, 0x9a, 0x9c, 0x5, 0x1c, 0xf, 0x2, 0x9b, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0xa2, 0x5, 0x1e, 0x10, 0x2, 0x9e, 0x9f, 0x7, 0x14, 
    0x2, 0x2, 0x9f, 0xa1, 0x5, 0x1e, 0x10, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xaa, 0x5, 0x20, 0x11, 0x2, 0xa6, 0xa7, 
    0x7, 0x15, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x20, 0x11, 0x2, 0xa8, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb4, 0x7, 0x18, 0x2, 0x2, 
    0xae, 0xb4, 0x7, 0x19, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x4, 0x2, 0x2, 0xb0, 
    0xb1, 0x5, 0x1c, 0xf, 0x2, 0xb1, 0xb2, 0x7, 0x5, 0x2, 0x2, 0xb2, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb3, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb8, 0x7, 0x16, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x17, 0x2, 
    0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf, 0x2f, 0x3f, 0x5d, 0x66, 0x6c, 0x70, 
    0x8a, 0x95, 0x9b, 0xa2, 0xaa, 0xb3, 0xb7, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
