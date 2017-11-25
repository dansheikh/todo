<template>
    <div class="row">
        <div class="col-md-4 col-md-offset-4">
            <ol id="tasks-todo" class="list-group">
                <li class="list-group-item" v-for="task in todos" v-on:click="emitTask">{{ task }}</li>
            </ol>
        </div>
    </div>
</template>

<script>
export default {
  name: 'task-list',
  props: {
      todos: {
          type: Array,
          required: true
      }
  },
  methods: {
      emitTask: function (evt) {
          let task = evt.target.innerHTML;
          this.$emit('remove-task', task);
      }
  }
}
</script>

<style>
    #tasks-todo {
        margin-top: 1em;
    }
    
    #tasks-todo:hover {
        cursor: pointer;
    }    
</style>

