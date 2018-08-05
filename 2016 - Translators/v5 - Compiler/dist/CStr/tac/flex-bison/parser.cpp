// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "flex-bison/parser.cpp" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 51 "flex-bison/parser.cpp" // lalr1.cc:407
// Unqualified %code blocks.
#line 116 "flex-bison/tac.ypp" // lalr1.cc:408

	using namespace tac;
	
	static SymbolTable* g_root_table = 0;
	static uint g_program_counter = 0;
	
	static int yylex(
		Parser::semantic_type* yylval,
		Parser::location_type* yylloc,
		Scanner& scanner);
	
	Symbol* make_char_const(char, const location&);
	std::vector<Symbol*>* make_char_array(std::string*, const location&);
	std::vector<Symbol*>* make_empty_array();
	void destroy_list(std::vector<Symbol*>*);
	bool register_symbol(Symbol*, std::list<Error>&);

#line 71 "flex-bison/parser.cpp" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "flex-bison/tac.ypp" // lalr1.cc:474
namespace tac {
#line 157 "flex-bison/parser.cpp" // lalr1.cc:474

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Scanner& scanner_yyarg, SymbolTable* table_yyarg, std::vector<Instruction*>*& instructions_yyarg, uint& start_address_yyarg, std::string file_yyarg, std::list<tac::Error>& errors_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      table (table_yyarg),
      instructions (instructions_yyarg),
      start_address (start_address_yyarg),
      file (file_yyarg),
      errors (errors_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 3: // "identifier"

#line 107 "flex-bison/tac.ypp" // lalr1.cc:599
        { delete (yysym.value.sval); }
#line 381 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 10: // "literal"

#line 107 "flex-bison/tac.ypp" // lalr1.cc:599
        { delete (yysym.value.sval); }
#line 388 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 72: // symbol

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 398 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 73: // name_and_type

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 408 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 75: // constant

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 418 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 76: // arr_size

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 428 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 77: // arr_constant

#line 114 "flex-bison/tac.ypp" // lalr1.cc:599
        { destroy_list((yysym.value.symbol_list)); }
#line 435 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 78: // constant_list

#line 114 "flex-bison/tac.ypp" // lalr1.cc:599
        { destroy_list((yysym.value.symbol_list)); }
#line 442 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 82: // label

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 452 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 85: // addressable

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 462 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 86: // target

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 472 "flex-bison/parser.cpp" // lalr1.cc:599
        break;

      case 87: // operand

#line 110 "flex-bison/tac.ypp" // lalr1.cc:599
        {
	if ((yysym.value.symbol) && (!(yysym.value.symbol)->registered))
		delete (yysym.value.symbol);
}
#line 482 "flex-bison/parser.cpp" // lalr1.cc:599
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 95 "flex-bison/tac.ypp" // lalr1.cc:725
{
	/* Stores the root symbol table. */
	g_root_table = table;
	
	/* Resets program counter. */
	g_program_counter = 0;

	/* Sets the initial location. */
	yyla.location.begin.filename = yyla.location.end.filename = &file;
}

#line 625 "flex-bison/parser.cpp" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 137 "flex-bison/tac.ypp" // lalr1.cc:847
    { instructions = (yystack_[0].value.instr_list); start_address = table->upper_bound(); }
#line 739 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 3:
#line 138 "flex-bison/tac.ypp" // lalr1.cc:847
    { instructions = (yystack_[0].value.instr_list); }
#line 745 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 5:
#line 144 "flex-bison/tac.ypp" // lalr1.cc:847
    { g_program_counter = table->upper_bound(); }
#line 751 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 7:
#line 152 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = (yystack_[0].value.symbol);
		if (s) register_symbol(s, errors);
	}
#line 760 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 9:
#line 162 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.symbol) = (yystack_[1].value.symbol); }
#line 766 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 10:
#line 164 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = (yystack_[3].value.symbol);
		Symbol *c = (yystack_[1].value.symbol);
		(yylhs.value.symbol) = 0;
		
		if (s && c) {
			if (s->type->kind != c->type->kind) {
				ON_ERROR("invalid constant initializer for type '" +  s->type->to_str() + "'", yystack_[1].location.begin);
				delete s;
			}
			else {
				s->value = c->value;
				memset(&c->value, 0, sizeof(c->value));
				(yylhs.value.symbol) = s;
			}
		}
		delete c;
	}
#line 789 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 11:
#line 183 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = (yystack_[2].value.symbol);
		Symbol *size = (yystack_[1].value.symbol);
		(yylhs.value.symbol) = 0;
		
		if (s && size) {
			s->type->array_size = (size_t) size->value.ival;
			s->value.arrval = new std::vector<Symbol*>();
			for (uint i = 0; i < s->type->array_size; ++i)
				s->value.arrval->push_back(
					new Symbol(SymbolTable::unique_id(0), yylhs.location, Symbol::VAR, new Type(*s->type))
				);
			(yylhs.value.symbol) = s;
		}
		else
			delete s;

		delete size;
	}
#line 813 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 12:
#line 203 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = (yystack_[5].value.symbol);
		std::vector<Symbol*> *init = (yystack_[1].value.symbol_list);
		(yylhs.value.symbol) = 0;
		
		if (s && init) {
			s->type->array_size = init->size();
			s->value.arrval = init;
			(yylhs.value.symbol) = s;
		}
		else {
			delete s;
			destroy_list(init);
		}
	}
#line 833 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 13:
#line 219 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = (yystack_[4].value.symbol);
		Symbol *size = (yystack_[3].value.symbol);
		std::vector<Symbol*> *init = (yystack_[1].value.symbol_list);
		(yylhs.value.symbol) = 0;
		
		if (s && size && init) {
			if (s->type->kind == init->back()->type->kind) {
				if (size->value.ival == (int) init->size()) {
					s->type->array_size = (size_t) size->value.ival;
					s->value.arrval = init;
					(yylhs.value.symbol) = s;
				}
				else
					ON_ERROR("array initializer with incompatible size", yystack_[1].location.begin);
			}
			else
				ON_ERROR("invalid constant array initializer for type '" +  s->type->to_str() + "'", yystack_[1].location.begin);
		}
		
		if (!(yylhs.value.symbol)) {
			delete s;
			destroy_list(init);
		}
		delete size;
	}
#line 864 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 14:
#line 249 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.symbol) = new Symbol((yystack_[0].value.sval), yystack_[0].location, Symbol::VAR, (yystack_[1].value.type)); }
#line 870 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 15:
#line 254 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.type) = new Type(Type::CHAR); }
#line 876 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 16:
#line 256 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.type) = new Type(Type::INT); }
#line 882 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 17:
#line 258 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.type) = new Type(Type::FLOAT); }
#line 888 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 18:
#line 263 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = new Symbol(SymbolTable::unique_id((yystack_[0].value.ival)), yystack_[0].location, Symbol::CONST, new Type(Type::INT));
		(yylhs.value.symbol)->value.ival = (yystack_[0].value.ival);
	}
#line 897 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 19:
#line 268 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = make_char_const((yystack_[0].value.cval), yystack_[0].location);
	}
#line 905 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 20:
#line 272 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = new Symbol(SymbolTable::unique_id((yystack_[0].value.fval)), yystack_[0].location, Symbol::CONST, new Type(Type::FLOAT));
		(yylhs.value.symbol)->value.fval = (yystack_[0].value.fval);
	}
#line 914 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 21:
#line 280 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = 0;
		if ((yystack_[1].value.ival) > 0) {
			(yylhs.value.symbol) = new Symbol(SymbolTable::unique_id((yystack_[1].value.ival)), yystack_[1].location, Symbol::CONST, new Type(Type::INT));
			(yylhs.value.symbol)->value.ival = (yystack_[1].value.ival);
		}
		else
			ON_ERROR("array size must be a positive integer", yystack_[1].location.begin);
	}
#line 928 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 22:
#line 293 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol_list) = make_char_array((yystack_[0].value.sval), yystack_[0].location);
		delete (yystack_[0].value.sval);
	}
#line 937 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 23:
#line 298 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.symbol_list) = (yystack_[1].value.symbol_list); }
#line 943 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 24:
#line 303 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol_list) = new std::vector<Symbol*>();
		(yylhs.value.symbol_list)->push_back((yystack_[0].value.symbol));
	}
#line 952 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 25:
#line 308 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		std::vector<Symbol*>* list = (yystack_[2].value.symbol_list);
		Symbol* c = (yystack_[0].value.symbol);
		(yylhs.value.symbol_list) = 0;
		
		if (list) {
			if (list->back()->type->kind == c->type->kind) {
				list->push_back(c);
				(yylhs.value.symbol_list) = list;
			}
			else {
				ON_ERROR("different constant types in array initializer", yystack_[0].location.begin);
				delete c;
				destroy_list(list);
			}
		}
		else
			delete c;
	}
#line 976 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 26:
#line 331 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr_list) = (yystack_[0].value.instr_list); }
#line 982 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 27:
#line 337 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr_list) = new std::vector<Instruction*>(); }
#line 988 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 28:
#line 339 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr_list) = (yystack_[1].value.instr_list); }
#line 994 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 29:
#line 341 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.instr_list) = (yystack_[2].value.instr_list);
		(yylhs.value.instr_list)->push_back((yystack_[1].value.instr));
		++g_program_counter;
	}
#line 1004 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 30:
#line 350 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.instr) = 0;
		if ((yystack_[1].value.symbol))
			(yylhs.value.instr) = (yystack_[0].value.instr);
	}
#line 1014 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 31:
#line 356 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = (yystack_[0].value.instr); }
#line 1020 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 32:
#line 361 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = new Symbol((yystack_[2].value.sval), yystack_[2].location, Symbol::LABEL, new Type(Type::ADDR));
		s->value.addrval = g_program_counter;
		
		if (register_symbol(s, errors))
			(yylhs.value.symbol) = s;
		else {
			delete s;
			(yylhs.value.symbol) = 0;
		}
	}
#line 1036 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 43:
#line 393 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.symbol) = new Symbol((yystack_[0].value.sval), yystack_[0].location, Symbol::VAR); }
#line 1042 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 44:
#line 395 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = new Symbol(SymbolTable::unique_id((int) ((yystack_[0].value.ival))), yystack_[0].location, Symbol::PARAM);
		(yylhs.value.symbol)->value.addrval = (yystack_[0].value.ival);
	}
#line 1051 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 45:
#line 403 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.symbol) = (yystack_[0].value.symbol); }
#line 1057 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 46:
#line 405 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = new Symbol(SymbolTable::unique_id((int) ((yystack_[0].value.ival))), yystack_[0].location, Symbol::TEMP);
		(yylhs.value.symbol)->value.addrval = (yystack_[0].value.ival);
	}
#line 1066 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 48:
#line 415 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.symbol) = new Symbol(SymbolTable::unique_id((int) ((yystack_[0].value.ival))), yystack_[0].location, Symbol::TEMP);
		(yylhs.value.symbol)->value.addrval = (yystack_[0].value.ival);
	}
#line 1075 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 50:
#line 425 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, (yystack_[5].value.opcode), (yystack_[4].value.symbol), (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1081 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 51:
#line 430 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::ADD; }
#line 1087 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 52:
#line 431 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::SUB; }
#line 1093 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 53:
#line 432 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::MUL; }
#line 1099 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 54:
#line 433 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::DIV; }
#line 1105 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 55:
#line 434 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::AND; }
#line 1111 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 56:
#line 435 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::OR; }
#line 1117 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 57:
#line 436 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::BAND; }
#line 1123 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 58:
#line 437 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::BOR; }
#line 1129 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 59:
#line 438 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::BXOR; }
#line 1135 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 60:
#line 439 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::SHL; }
#line 1141 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 61:
#line 440 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::SHR; }
#line 1147 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 62:
#line 441 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::MOD; }
#line 1153 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 63:
#line 442 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::SEQ; }
#line 1159 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 64:
#line 443 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::SLT; }
#line 1165 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 65:
#line 444 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::SLEQ; }
#line 1171 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 66:
#line 449 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, (yystack_[3].value.opcode), (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1177 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 67:
#line 454 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::MINUS; }
#line 1183 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 68:
#line 455 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::NOT; }
#line 1189 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 69:
#line 456 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::BNOT; }
#line 1195 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 70:
#line 457 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::CHTOINT; }
#line 1201 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 71:
#line 458 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::CHTOFL; }
#line 1207 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 72:
#line 459 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::INTTOFL; }
#line 1213 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 73:
#line 460 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::INTTOCH; }
#line 1219 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 74:
#line 461 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::FLTOINT; }
#line 1225 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 75:
#line 462 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.opcode) = Instruction::FLTOCH; }
#line 1231 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 76:
#line 467 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVVV, (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1237 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 77:
#line 468 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVVD, (yystack_[3].value.symbol), (yystack_[0].value.symbol)); }
#line 1243 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 78:
#line 469 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVVA, (yystack_[3].value.symbol), (yystack_[0].value.symbol)); }
#line 1249 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 79:
#line 472 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVVA, (yystack_[3].value.symbol), (yystack_[0].value.symbol)); }
#line 1255 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 80:
#line 474 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVVI, (yystack_[5].value.symbol), (yystack_[3].value.symbol), (yystack_[1].value.symbol)); }
#line 1261 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 81:
#line 475 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVDV, (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1267 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 82:
#line 476 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVDD, (yystack_[3].value.symbol), (yystack_[0].value.symbol)); }
#line 1273 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 83:
#line 477 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVDA, (yystack_[3].value.symbol), (yystack_[0].value.symbol)); }
#line 1279 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 84:
#line 478 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVDI, (yystack_[5].value.symbol), (yystack_[1].value.symbol), (yystack_[3].value.symbol)); }
#line 1285 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 85:
#line 479 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVIV, (yystack_[5].value.symbol), (yystack_[0].value.symbol), (yystack_[3].value.symbol)); }
#line 1291 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 86:
#line 480 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVID, (yystack_[6].value.symbol), (yystack_[0].value.symbol), (yystack_[4].value.symbol)); }
#line 1297 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 87:
#line 481 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MOVIA, (yystack_[6].value.symbol), (yystack_[0].value.symbol), (yystack_[4].value.symbol)); }
#line 1303 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 88:
#line 486 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::JUMP, (yystack_[0].value.symbol)); }
#line 1309 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 89:
#line 487 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::PARAM, (yystack_[0].value.symbol)); }
#line 1315 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 90:
#line 488 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::PRINT, (yystack_[0].value.symbol)); }
#line 1321 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 91:
#line 489 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::PRINTLN); }
#line 1327 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 92:
#line 490 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::PRINTLN, (yystack_[0].value.symbol)); }
#line 1333 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 93:
#line 491 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::SCANC, (yystack_[0].value.symbol)); }
#line 1339 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 94:
#line 492 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::SCANI, (yystack_[0].value.symbol)); }
#line 1345 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 95:
#line 493 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::SCANF, (yystack_[0].value.symbol)); }
#line 1351 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 96:
#line 494 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MEMF, (yystack_[0].value.symbol)); }
#line 1357 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 97:
#line 495 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::PUSH, (yystack_[0].value.symbol)); }
#line 1363 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 98:
#line 496 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::POP, (yystack_[0].value.symbol)); }
#line 1369 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 99:
#line 497 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::RAND, (yystack_[0].value.symbol)); }
#line 1375 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 100:
#line 502 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::MEMA, (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1381 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 101:
#line 507 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::BRZ, (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1387 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 102:
#line 508 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::BRNZ, (yystack_[2].value.symbol), (yystack_[0].value.symbol)); }
#line 1393 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 103:
#line 512 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		Symbol *s = new Symbol(SymbolTable::unique_id(0), yystack_[0].location, Symbol::CONST, new Type(Type::INT));
		s->value.ival = 0;
		(yylhs.value.instr) = new Instruction(yylhs.location, Instruction::CALL, (yystack_[0].value.symbol), s);
	}
#line 1403 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 104:
#line 518 "flex-bison/tac.ypp" // lalr1.cc:847
    {
		(yylhs.value.instr) = 0;
		
		if ((yystack_[0].value.ival) >= 0) {
			Symbol *s = new Symbol(SymbolTable::unique_id((yystack_[0].value.ival)), yystack_[0].location, Symbol::CONST, new Type(Type::INT));
			s->value.ival = (yystack_[0].value.ival);
			(yylhs.value.instr) = new Instruction(yylhs.location, Instruction::CALL, (yystack_[2].value.symbol), s);
		}
		else
			ON_ERROR("parameter count must be a non-negative number", yystack_[0].location.begin);
	}
#line 1419 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 105:
#line 533 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::RETURN); }
#line 1425 "flex-bison/parser.cpp" // lalr1.cc:847
    break;

  case 106:
#line 534 "flex-bison/tac.ypp" // lalr1.cc:847
    { (yylhs.value.instr) = new Instruction(yylhs.location, Instruction::RETURN, (yystack_[0].value.symbol)); }
#line 1431 "flex-bison/parser.cpp" // lalr1.cc:847
    break;


#line 1435 "flex-bison/parser.cpp" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -93;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
      -8,   -93,   -93,     7,    11,    20,   -93,    16,   166,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,    12,    21,   -45,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   128,   128,     9,   128,   128,   128,
     128,    42,    42,    42,    42,   128,    42,   128,   128,   128,
      42,   -93,   -23,   208,   -93,   -93,    42,   -93,    42,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,    73,     2,     3,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -13,    23,    42,    62,   -42,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,    24,   -93,   -93,    25,   -93,   -93,   -93,
     -93,   -93,    26,    27,    18,    32,    14,   -93,     6,    37,
     128,   128,    34,    46,   128,    35,   128,    76,   128,   128,
     -93,   -93,     6,   -93,    73,    38,   -93,   -93,   -93,    49,
      39,    50,    42,    62,    52,   -93,   -93,   -93,    53,   -93,
      55,   -93,    15,   -93,    42,    62,    54,   -93,    62,    63,
     -93,   -93,   128,   128,   -93,   -93,    73,   -93,   -93,   128,
     -93,   115,    65,   -93,   -93,    67,    42,    62,   -93,   -93,
     -93,   -93,   -93
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     6,    27,     0,     0,     0,     3,     5,    26,     4,
       1,     2,    15,    16,    17,     8,     7,     0,     0,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
      91,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,    28,     0,     0,    31,    35,     0,    36,     0,    37,
      38,    39,    40,    41,    42,     9,     0,     0,     0,    14,
      33,    43,    46,    48,    44,    18,    19,    20,    49,    45,
      47,     0,     0,     0,     0,     0,    88,    89,    90,    92,
      93,    94,    95,     0,    96,    99,   103,   106,    97,    98,
      29,    30,     0,     0,     0,     0,     0,    11,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    21,     0,    22,     0,     0,    34,   101,   102,     0,
       0,     0,     0,     0,    47,    76,   100,   104,     0,    66,
       0,    24,     0,    13,     0,     0,    47,    81,     0,     0,
      77,    78,     0,     0,    12,    23,     0,    82,    83,     0,
      79,     0,     0,    50,    25,     0,     0,     0,    85,    80,
      84,    86,    87
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -93,   -93,    81,   -93,   -93,   -93,   -93,   -75,   -93,    -4,
     -93,   124,   -93,   -93,   -93,   -93,    75,   -92,   -46,   -22,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,     4,     5,     7,    16,    17,    18,    88,    78,   135,
     152,     6,     8,    62,    63,   119,    64,    89,    90,    91,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
  };

  const unsigned char
  Parser::yytable_[] =
  {
      95,   114,   123,     1,     2,   100,   101,   102,   103,   115,
     105,    10,    81,    82,   109,    84,   133,   124,     1,    80,
     112,   125,   113,    92,    79,    96,    97,    98,    99,    12,
      13,    14,     2,   104,   110,   106,   107,   108,    81,    82,
      83,    84,    85,    86,    87,    81,    82,   122,    84,     3,
     120,   161,    81,    82,    83,    84,    85,    86,    87,   151,
     117,   118,   116,   168,     3,    81,   170,   134,    84,    75,
      76,    77,   132,    15,    93,   130,    94,   165,   166,   144,
      85,    86,    87,   147,     9,   182,   121,   126,   127,   128,
     129,   174,   131,   156,   136,   153,   160,   139,   137,   138,
     142,   143,   141,   145,   146,   158,   148,   149,   167,   140,
     159,   162,   164,   169,   154,   155,   163,   157,    81,    82,
      83,    84,    85,    86,    87,   179,   171,   180,   150,    11,
     181,    81,    82,    83,    84,    85,    86,    87,   111,     0,
     172,   173,     0,     0,     0,     0,     0,   175,     0,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60
  };

  const short int
  Parser::yycheck_[] =
  {
      46,    76,    94,    11,    12,    51,    52,    53,    54,     7,
      56,     0,     3,     4,    60,     6,    10,    59,    11,    64,
      66,    63,    68,    45,     3,    47,    48,    49,    50,    13,
      14,    15,    12,    55,    57,    57,    58,    59,     3,     4,
       5,     6,     7,     8,     9,     3,     4,    93,     6,    57,
      63,   143,     3,     4,     5,     6,     7,     8,     9,   134,
      57,    58,    60,   155,    57,     3,   158,    61,     6,    57,
      58,    59,    58,    57,    65,    57,    67,    62,    63,   125,
       7,     8,     9,     7,     3,   177,    63,    63,    63,    63,
      63,   166,    60,   139,    57,    57,   142,    63,   120,   121,
      65,    66,   124,   125,   126,    66,   128,   129,   154,    63,
      60,    59,    57,    59,    65,    66,    63,   139,     3,     4,
       5,     6,     7,     8,     9,    60,    63,    60,   132,     5,
     176,     3,     4,     5,     6,     7,     8,     9,    63,    -1,
     162,   163,    -1,    -1,    -1,    -1,    -1,   169,    -1,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,    11,    12,    57,    69,    70,    79,    71,    80,    70,
       0,    79,    13,    14,    15,    57,    72,    73,    74,     3,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    81,    82,    84,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    57,    58,    59,    76,     3,
      64,     3,     4,     5,     6,     7,     8,     9,    75,    85,
      86,    87,    87,    65,    67,    86,    87,    87,    87,    87,
      86,    86,    86,    86,    87,    86,    87,    87,    87,    86,
      57,    84,    86,    86,    75,     7,    60,    57,    58,    83,
      63,    63,    86,    85,    59,    63,    63,    63,    63,    63,
      57,    60,    58,    10,    61,    77,    57,    87,    87,    63,
      63,    87,    65,    66,    86,    87,    87,     7,    87,    87,
      77,    75,    78,    57,    65,    66,    86,    87,    66,    60,
      86,    85,    59,    63,    57,    62,    63,    86,    85,    59,
      85,    63,    87,    87,    75,    87,    65,    66,    87,    60,
      60,    86,    85
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    68,    69,    69,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    73,    74,    74,    74,    75,    75,
      75,    76,    77,    77,    78,    78,    79,    80,    80,    80,
      81,    81,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      88,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    95,    95,    96,    96,    97,    97
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     2,     1,     2,     2,     0,     2,     2,     2,
       4,     3,     6,     5,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     2,     0,     2,     3,
       2,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       7,     5,     6,     6,     8,     7,     8,     8,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     4,     4,     2,     4,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"identifier\"", "\"temp_ref\"",
  "\"special reg\"", "\"param_ref\"", "\"integer constant\"",
  "\"char constant\"", "\"float constant\"", "\"literal\"", "\".table\"",
  "\".code\"", "CHAR", "INT", "FLOAT", "ADD", "SUB", "MUL", "DIV", "AND",
  "OR", "BAND", "BOR", "BXOR", "SHL", "SHR", "MOD", "SEQ", "SLT", "SLEQ",
  "MINUS", "NOT", "BNOT", "CHTOINT", "CHTOFL", "INTTOFL", "INTTOCH",
  "FLTOINT", "FLTOCH", "BRZ", "BRNZ", "MOV", "JUMP", "PARAM", "PRINT",
  "PRINTLN", "SCANC", "SCANI", "SCANF", "MEMA", "MEMF", "RAND", "CALL",
  "RETURN", "PUSH", "POP", "EOL", "'='", "'['", "']'", "'{'", "'}'", "','",
  "':'", "'*'", "'&'", "'@'", "$accept", "tac_program", "table_block",
  "symbol_list", "symbol", "name_and_type", "type", "constant", "arr_size",
  "arr_constant", "constant_list", "code_block", "instruction_list",
  "instruction", "label", "empty_lines", "cmd", "addressable", "target",
  "operand", "binary_operation", "binary_opname", "unary_operation",
  "unary_opname", "assignment", "single_operand_cmd", "mema", "branch",
  "call", "ret", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   137,   137,   138,   143,   144,   149,   152,   157,   162,
     164,   183,   203,   219,   249,   254,   256,   258,   263,   268,
     272,   280,   293,   298,   303,   308,   331,   337,   339,   341,
     350,   356,   361,   375,   377,   382,   383,   384,   385,   386,
     387,   388,   389,   393,   395,   403,   405,   413,   415,   420,
     425,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   449,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   467,   468,   469,   472,
     474,   475,   476,   477,   478,   479,   480,   481,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     502,   507,   508,   512,   518,   533,   534
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
       2,     2,    65,     2,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,     2,
       2,    58,     2,     2,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
    };
    const unsigned int user_token_number_max_ = 312;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 6 "flex-bison/tac.ypp" // lalr1.cc:1155
} // tac
#line 2004 "flex-bison/parser.cpp" // lalr1.cc:1155
#line 538 "flex-bison/tac.ypp" // lalr1.cc:1156


#include "scanner.hpp"

void Parser::error(const Parser::location_type& l, const std::string& msg) {
	std::string& file = *l.begin.filename;
	int line = l.begin.line;
	int col = l.begin.column;
	std::ostream& out = std::cerr;
	
	if (file.size() > 0) {
		out << file.c_str();
		if (line > 0) {
			out << "(" << line;
			if (col > 0)
				out << "," << col;
			out << ")";
		}
		out << ": ";
	}

	out << msg.c_str();
}

static int yylex(
		Parser::semantic_type* yylval,
		Parser::location_type* yylloc,
		Scanner& scanner) {
	
	return scanner.yylex(yylval, yylloc);
}

Symbol* make_char_const(char c, const location &loc) {
	std::string *id =
			(c >= 32) ? new std::string(std::string() + c) : SymbolTable::unique_id((int) c);
	Symbol *s = new Symbol(id, loc, Symbol::CONST, new Type(Type::CHAR));
	s->value.cval = c;
	return s;
}

std::vector<Symbol*>* make_char_array(std::string *str, const location &loc) {
	std::vector<Symbol*>* v = new std::vector<Symbol*>();
	v->reserve(str->size() + 1);
	for (std::string::iterator i = str->begin(); i != str->end(); ++i)
		v->push_back(make_char_const(*i, loc));
	v->push_back(make_char_const('\0', loc));
	return v;
}

void destroy_list(std::vector<Symbol*> *list) {
	if (list) {
		for (std::vector<Symbol*>::iterator i = list->begin(); i != list->end(); ++i) {
			if (!(*i)->registered)
				delete (*i);
		}
		delete list;
	}
}

bool register_symbol(Symbol *s, std::list<Error> &errors) {
	const Symbol *aux = g_root_table->get(*s->id);
	if (aux) {
		std::ostringstream ss;
		ss << "duplicate symbol '" << *s->id
				<< "', previously defined at (" << aux->loc.begin.line << "," << aux->loc.begin.column << ")";
		ON_ERROR(ss.str(), s->loc.begin);
		return false;
	}
	
	g_root_table->put(s);
	return true;
}
