//===--- ArgumentLabel.h - Argument Label -----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines interfaces used to represent argument labels (part of
// C++ Named Parameters extension) during parsing.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_SEMA_ARGUMENT_LABEL_H
#define LLVM_CLANG_SEMA_ARGUMENT_LABEL_H

#include "clang/Basic/SourceLocation.h"
#include "llvm/ADT/SmallVector.h"

namespace clang {

class Expr;
class IdentifierInfo;
class Sema;

/// ArgumentLabel - The argument label of a C++ labelled argument.
///
class ArgumentLabel {
private:
  const IdentifierInfo *II;
  SourceLocation StartLoc;
  SourceLocation LabelLoc;

public:

  ArgumentLabel() : II(nullptr) {}

  ArgumentLabel(const IdentifierInfo *II,
             SourceLocation StartLoc,
             SourceLocation LabelLoc) : II(II),
              StartLoc(StartLoc), LabelLoc(LabelLoc) {}

  bool isSet() const { return II != nullptr; }

  const IdentifierInfo *getIdentifier() const {
    return II;
  }

  SourceLocation getStartLoc() const {
    return StartLoc;
  }

  SourceLocation getLabelLoc() const {
    return LabelLoc;
  }

  /// ClearExprs - Null out any expression references, which prevents
  /// them from being 'delete'd later.
  void ClearExprs(Sema &Actions) {}

  /// FreeExprs - Release any unclaimed memory for the expressions in
  /// this designator.
  void FreeExprs(Sema &Actions) {}
};

} // end namespace clang

#endif
