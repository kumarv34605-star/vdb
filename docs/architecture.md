# VDB — System Architecture

## 1. Architecture Overview

VDB is organized as a layered database engine.

```text
                    +------------------+
                    |      Client      |
                    |   CLI / TCP      |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    |   SQL Layer      |
                    | Lexer / Parser   |
                    | AST              |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    |  Query Engine    |
                    | Planner /        |
                    | Executor         |
                    +--------+---------+
                             |
              +--------------+--------------+
              |                             |
              v                             v
      +---------------+             +---------------+
      | Index Manager |             | Transaction   |
      | B+ Tree       |             | Manager       |
      +-------+-------+             | WAL / Recovery|
              |                     +-------+-------+
              |                             |
              +--------------+--------------+
                             |
                             v
                    +------------------+
                    |   Buffer Pool    |
                    | Page Cache       |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    | Storage Engine   |
                    | Pages / Records  |
                    | File I/O         |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    |  Linux / FS      |
                    |  Local Disk      |
                    +------------------+

# VDB — System Architecture

## 1. Architecture Overview

VDB is organized as a layered database engine.

```text
                    +------------------+
                    |      Client      |
                    |   CLI / TCP      |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    |   SQL Layer      |
                    | Lexer / Parser   |
                    | AST               |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    |  Query Engine    |
                    | Planner /        |
                    | Executor         |
                    +--------+---------+
                             |
              +--------------+--------------+
              |                             |
              v                             v
      +---------------+             +---------------+
      | Index Manager |             | Transaction   |
      | B+ Tree       |             | Manager       |
      +-------+-------+             | WAL / Recovery|
              |                     +-------+-------+
              |                             |
              +--------------+--------------+
                             |
                             v
                    +------------------+
                    |   Buffer Pool    |
                    | Page Cache        |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    | Storage Engine   |
                    | Pages / Records  |
                    | File I/O         |
                    +--------+---------+
                             |
                             v
                    +------------------+
                    |  Linux / FS      |
                    |  Local Disk       |
                    +------------------+
