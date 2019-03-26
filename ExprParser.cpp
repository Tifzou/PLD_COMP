
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
    setState(16);
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
    setState(18);
    match(ExprParser::T__0);
    setState(19);
    match(ExprParser::T__1);
    setState(20);
    match(ExprParser::T__2);
    setState(21);
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
    setState(23);
    match(ExprParser::T__3);
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::TYPEINT

    || _la == ExprParser::TYPECHAR) {
      setState(24);
      code();
      setState(29);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(30);
    ret();
    setState(31);
    match(ExprParser::T__4);
    setState(32);
    match(ExprParser::T__5);
   
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

ExprParser::TypevarContext* ExprParser::CodeContext::typevar() {
  return getRuleContext<ExprParser::TypevarContext>(0);
}

ExprParser::VariContext* ExprParser::CodeContext::vari() {
  return getRuleContext<ExprParser::VariContext>(0);
}


size_t ExprParser::CodeContext::getRuleIndex() const {
  return ExprParser::RuleCode;
}


antlrcpp::Any ExprParser::CodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCode(this);
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
    enterOuterAlt(_localctx, 1);
    setState(34);
    typevar();
    setState(35);
    vari();
    setState(36);
    match(ExprParser::T__4);
   
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

tree::TerminalNode* ExprParser::RetContext::VAR() {
  return getToken(ExprParser::VAR, 0);
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
  enterRule(_localctx, 8, ExprParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(ExprParser::T__6);
    setState(39);
    match(ExprParser::VAR);
   
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

//----------------- AffContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::AffContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

tree::TerminalNode* ExprParser::AffContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::AffContext::AffContext(VariContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::AffContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAff(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::DecContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::DecContext::DecContext(VariContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDec(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpressionContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ExpressionContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::ExprContext* ExprParser::ExpressionContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ExpressionContext::ExpressionContext(VariContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}
ExprParser::VariContext* ExprParser::vari() {
  VariContext *_localctx = _tracker.createInstance<VariContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleVari);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(48);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VariContext *>(_tracker.createInstance<ExprParser::DecContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(41);
      match(ExprParser::VAR);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VariContext *>(_tracker.createInstance<ExprParser::AffContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(42);
      match(ExprParser::VAR);
      setState(43);
      match(ExprParser::T__7);
      setState(44);
      match(ExprParser::INT);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VariContext *>(_tracker.createInstance<ExprParser::ExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(45);
      match(ExprParser::VAR);
      setState(46);
      match(ExprParser::T__7);
      setState(47);
      expr(0);
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


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ParContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ParContext::ParContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::ParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::DivContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::DivContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::DivContext::DivContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::DivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::AddContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::AddContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::AddContext::AddContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::SubContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::SubContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::SubContext::SubContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::SubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::MultContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::MultContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::MultContext::MultContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::VarContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::VarContext::VarContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LdconstContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::LdconstContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::LdconstContext::LdconstContext(ExprContext *ctx) { copyFrom(ctx); }


antlrcpp::Any ExprParser::LdconstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitLdconst(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, ExprParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(57);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::VAR: {
        _localctx = _tracker.createInstance<VarContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(51);
        match(ExprParser::VAR);
        break;
      }

      case ExprParser::INT: {
        _localctx = _tracker.createInstance<LdconstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(52);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::T__1: {
        _localctx = _tracker.createInstance<ParContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(53);
        match(ExprParser::T__1);
        setState(54);
        expr(0);
        setState(55);
        match(ExprParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(73);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(71);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(59);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(60);
          match(ExprParser::T__8);
          setState(61);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(62);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(63);
          match(ExprParser::T__9);
          setState(64);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(65);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(66);
          match(ExprParser::T__10);
          setState(67);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<SubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(68);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(69);
          match(ExprParser::T__11);
          setState(70);
          expr(5);
          break;
        }

        } 
      }
      setState(75);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
  enterRule(_localctx, 14, ExprParser::RuleTypevar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::TYPEINT: {
        _localctx = dynamic_cast<TypevarContext *>(_tracker.createInstance<ExprParser::IntContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(76);
        match(ExprParser::TYPEINT);
        break;
      }

      case ExprParser::TYPECHAR: {
        _localctx = dynamic_cast<TypevarContext *>(_tracker.createInstance<ExprParser::CharContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(77);
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

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "base", "core", "code", "ret", "vari", "expr", "typevar"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'int main'", "'('", "')'", "'{'", "';'", "'}'", "'return'", "'='", 
  "'*'", "'/'", "'+'", "'-'", "'int'", "'char'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "TYPEINT", "TYPECHAR", 
  "INT", "VAR", "WS"
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
    0x3, 0x13, 0x53, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x1c, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x1f, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x33, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x3c, 0xa, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4a, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x4d, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x51, 
    0xa, 0x9, 0x3, 0x9, 0x2, 0x3, 0xe, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x2, 0x2, 0x2, 0x54, 0x2, 0x12, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x6, 0x19, 0x3, 0x2, 0x2, 0x2, 0x8, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x28, 0x3, 0x2, 0x2, 0x2, 0xc, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x13, 0x5, 0x4, 0x3, 0x2, 0x13, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x15, 0x7, 0x3, 0x2, 0x2, 0x15, 0x16, 0x7, 0x4, 0x2, 0x2, 0x16, 
    0x17, 0x7, 0x5, 0x2, 0x2, 0x17, 0x18, 0x5, 0x6, 0x4, 0x2, 0x18, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x19, 0x1d, 0x7, 0x6, 0x2, 0x2, 0x1a, 0x1c, 0x5, 
    0x8, 0x5, 0x2, 0x1b, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x21, 0x5, 0xa, 0x6, 0x2, 0x21, 0x22, 0x7, 0x7, 0x2, 0x2, 0x22, 
    0x23, 0x7, 0x8, 0x2, 0x2, 0x23, 0x7, 0x3, 0x2, 0x2, 0x2, 0x24, 0x25, 
    0x5, 0x10, 0x9, 0x2, 0x25, 0x26, 0x5, 0xc, 0x7, 0x2, 0x26, 0x27, 0x7, 
    0x7, 0x2, 0x2, 0x27, 0x9, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x9, 
    0x2, 0x2, 0x29, 0x2a, 0x7, 0x12, 0x2, 0x2, 0x2a, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x33, 0x7, 0x12, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x12, 0x2, 0x2, 
    0x2d, 0x2e, 0x7, 0xa, 0x2, 0x2, 0x2e, 0x33, 0x7, 0x11, 0x2, 0x2, 0x2f, 
    0x30, 0x7, 0x12, 0x2, 0x2, 0x30, 0x31, 0x7, 0xa, 0x2, 0x2, 0x31, 0x33, 
    0x5, 0xe, 0x8, 0x2, 0x32, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x32, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x33, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x35, 0x8, 0x8, 0x1, 0x2, 0x35, 0x3c, 0x7, 0x12, 0x2, 
    0x2, 0x36, 0x3c, 0x7, 0x11, 0x2, 0x2, 0x37, 0x38, 0x7, 0x4, 0x2, 0x2, 
    0x38, 0x39, 0x5, 0xe, 0x8, 0x2, 0x39, 0x3a, 0x7, 0x5, 0x2, 0x2, 0x3a, 
    0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x34, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3e, 0xc, 0x9, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0xb, 
    0x2, 0x2, 0x3f, 0x4a, 0x5, 0xe, 0x8, 0xa, 0x40, 0x41, 0xc, 0x8, 0x2, 
    0x2, 0x41, 0x42, 0x7, 0xc, 0x2, 0x2, 0x42, 0x4a, 0x5, 0xe, 0x8, 0x9, 
    0x43, 0x44, 0xc, 0x7, 0x2, 0x2, 0x44, 0x45, 0x7, 0xd, 0x2, 0x2, 0x45, 
    0x4a, 0x5, 0xe, 0x8, 0x8, 0x46, 0x47, 0xc, 0x6, 0x2, 0x2, 0x47, 0x48, 
    0x7, 0xe, 0x2, 0x2, 0x48, 0x4a, 0x5, 0xe, 0x8, 0x7, 0x49, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x40, 0x3, 0x2, 0x2, 0x2, 0x49, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x51, 0x7, 0xf, 0x2, 0x2, 0x4f, 0x51, 0x7, 0x10, 0x2, 0x2, 0x50, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x8, 0x1d, 0x32, 0x3b, 0x49, 0x4b, 0x50, 
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
